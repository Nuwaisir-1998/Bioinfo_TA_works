#include<bits/stdc++.h>
using namespace std;
#define vt vector

struct D_mat{
    map<pair<int, int>, double> D_map;
    
    void add_edge(int u, int v, double weight){
        D_map[{min(u, v), max(u, v)}] = weight;
    }
    void remove_row_col(int row, int col){
        D_map.erase({min(row, col), max(row, col)});
    }
    double get_value(int u, int v){
        return D_map[{min(u, v), max(u, v)}];
    }
    void print(){
        vt<vt<int>> adj(1000);
        vt<vt<int>> cost(1000);
        for(auto ele : D_map){
            adj[ele.first.first].push_back(ele.first.second);
            cost[ele.first.first].push_back(get_value(ele.first.first, ele.first.second));
            if(ele.first.first == ele.first.second) continue;
            adj[ele.first.second].push_back(ele.first.first);
            cost[ele.first.second].push_back(get_value(ele.first.first, ele.first.second));
        }
        for(int i=0;i<adj.size();i++){
            if(adj[i].empty()) continue;
            cout << i << ": ";
            for(auto ele : adj[i]){
                cout << ele << " ";
            }
            cout << endl;
        }
        cout << "cost:" << endl;
        for(int i=0;i<cost.size();i++){
            if(cost[i].empty()) continue;
            cout << i << ": ";
            for(auto ele : cost[i]){
                cout << ele << " ";
            }
            cout << endl;
        }
    }

};

struct Tree{
    unordered_map<int, vt<int>> adj;
    int n;
    D_mat distance_matrix;
    
    void add_edge(int u, int v, int length){
        adj[u].push_back(v);
        adj[v].push_back(u);
        distance_matrix.add_edge(u, v, length);
    }

    void print(){
        for(auto ele : adj){
            if(ele.second.empty()) continue;
            cout << ele.first << ": ";
            for(auto v : ele.second){
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

D_mat construct_NJ_matrix(D_mat & D, int n){
    D_mat d_star;
    map<int,double> tot_dist;
    for(auto edge : D.D_map){
        tot_dist[edge.first.first] += edge.second;
        tot_dist[edge.first.second] += edge.second;
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         d_star.add_edge(i, j, D.get_value(i, j) * (n - 2) - tot_dist[i] - tot_dist[j]);
    //         if(i == j) d_star.add_edge(i, j, 0);
    //     }
    // }
    for(auto ele : D.D_map){
        int i = ele.first.first;
        int j = ele.first.second;
        d_star.add_edge(i, j, D.get_value(i, j) * (n - 2) - tot_dist[i] - tot_dist[j]);
        if(i == j) d_star.add_edge(i, j, 0);
    }
    return d_star;
}

pair<int,int> find_min(D_mat D){
    int mi, mj, mn = INT_MAX;
    for(auto ele : D.D_map){
        int i = ele.first.first;
        int j = ele.first.second;
        if(ele.second < mn and i != j){
            mn = ele.second;
            mi = i;
            mj = j;
        }
    }
    return {mi, mj};
}

double total_dist(D_mat & D, int row){
    int sum = 0;
    set<int> vertices;
    for(auto ele : D.D_map){
        vertices.insert(ele.first.first);
        vertices.insert(ele.first.second);
    }
    for(auto i : vertices){
        if(row != i)
            sum += D.get_value(row, i);
    }
    return sum;
}

int new_row = -1;

Tree Neighbor_joining(D_mat & D, int n){
    if(n == 2){
        Tree tree;
        set<int> vertices;
        for(auto v : D.D_map) {
            vertices.insert(v.first.first);
            vertices.insert(v.first.second);
        }
        auto itr = vertices.begin();
        auto itr2 = vertices.begin();
        itr2++;
        tree.add_edge(*itr, *itr2, D.get_value(*itr, *itr2));
        return tree;
    }
    D_mat D_star = construct_NJ_matrix(D, n);
    pair<int,int> ij = find_min(D_star);
    int i = ij.first;
    int j = ij.second;
    // cout << "-----------start----------" << endl;
    // for(auto ele : D.D_map){
    //     cout << ele.first.first << " " << ele.first.second << endl;
    // }
    // D.print();
    // cout << endl;
    // D_star.print();
    // cout << endl;
    // cout << i << " " << j << endl;
    // cout << "----------\n";

    double delta = (total_dist(D, i) - total_dist(D, j)) / (n - 2);
    double limb_length_i = (D.get_value(i, j) + delta) / 2;
    double limb_length_j = (D.get_value(i, j) - delta) / 2;
    assert(new_row != -1);
    set<int> vertices;
    for(auto ele : D.D_map){
        vertices.insert(ele.first.first);
        vertices.insert(ele.first.second);
    }
    vertices.insert(new_row);
    // for(auto ele : D.D_map){
    //     cout << ele.first.first << " " << ele.first.second << endl;
    // }
    for(auto k : vertices){
        D.add_edge(k, new_row, ((D.get_value(k, i) + D.get_value(k, j) - D.get_value(i, j)) / 2));
        if(k == new_row) D.add_edge(k, new_row, 0);
    }
    int m = new_row;
    new_row++;
    // for(auto ele : D.D_map){
    //     cout << ele.first.first << " " << ele.first.second << endl;
    // }
    for(auto c : vertices) {
        D.remove_row_col(i, c);
        D.remove_row_col(j, c);
    }
    // cout << "|" << endl;
    // for(auto ele : D.D_map){
    //     cout << ele.first.first << " " << ele.first.second << endl;
    // }
    Tree T = Neighbor_joining(D, n-1);
    T.add_edge(m, i, limb_length_i);
    T.add_edge(m, j, limb_length_j);
    // cout << "Adding : " << m << " " << i << endl;
    // cout << "Adding : " << m << " " << j << endl;
    return T;
}

void solve(){
    int n, i, j;
    cin >> n;
    new_row = n;
    D_mat D;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            double w;
            cin >> w;
            D.add_edge(i, j, w);
        }
    }
    Tree tree = Neighbor_joining(D, n);
    tree.print();
}

int main(){
    freopen("./in.txt", "r", stdin);
    solve();
    return 0;
}