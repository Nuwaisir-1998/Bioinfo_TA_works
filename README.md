# Bioinfo_TA_works

## Neighbor Joining Algorithm (NJ)

## Problem:
Reconstruct the evolutionary tree given the distance matrix.

## How to Run The Code:
Go to the NJ folder. Put the input in **in.txt** file. The first line of the input file denotes the number of rows and columns. Then put the matrix.
Open a terminal there. Then run the follwing command.
```
./main.sh
```
Make sure to have the execution permission by running:
```
chmod +x main.sh
```


Input /Ouput:<br/>
Input:<br/>
4<br/>
0 13 21 22<br/>
13 0 12 13<br/>
21 12 0 13<br/>
22 13 13 0<br/>
The first line denotes the number of nodes(x) in the tree.The next x lines indicate the distance matrix.<br/>
step 1:<br/>
Tree matrix<br/>
0: 0 1 2 3<br/>
1: 0 1 2 3<br/>
2: 0 1 2 3<br/>
3: 0 1 2 3<br/>
Cost:<br/>
0: 0 13 21 22<br/>
1: 13 0 12 13<br/
2: 21 12 0 1<br/>
3: 22 13 13 0<br/>
Tree:<br/>
![image](https://user-images.githubusercontent.com/40664860/122535022-f4e60180-d044-11eb-9688-f977e1d92e6d.png)<br/>
step 2:<br/>
Tree matrix<br/>
2: 2 3 4<br/>
3: 2 3 4<br/>
4: 2 3 4<br/>
Cost:<br/>
2: 0 13 10<br/>
3: 13 0 11<br/>
4: 10 11 0<br/>
Tree:<br/>
![image](https://user-images.githubusercontent.com/40664860/122535377-5312e480-d045-11eb-8648-8612ec88a938.png)<br/>
step 3:<br/>
Distance matrix:<br/>
4: 4 5<br/>
5: 4 5<br/>
Cost:<br/>
4: 0 4<br/>
5: 4 0<br/>
Tree:<br/>
![image](https://user-images.githubusercontent.com/40664860/122535515-79d11b00-d045-11eb-85a4-964b0d8d2153.png)<br/>
Example 2:<br/>
8<br/>
0 7 7 7 7 7 7 7<br/>
7 0 4 4 4 4 4 4<br/>
7 4 0 2 2 2 2 2<br/>
7 4 2 0 2 2 2 2<br/>
7 4 2 2 0 2 2 2<br/>
7 4 2 2 2 0 2 2<br/>
7 4 2 2 2 2 0 2<br/>
7 4 2 2 2 2 2 0<br/>
Step 1:<br/>
Tree Matrix:<br/>
0: 0 1 2 3 4 5 6 7<br/>
1: 0 1 2 3 4 5 6 7<br/>
2: 0 1 2 3 4 5 6 7<br/>
3: 0 1 2 3 4 5 6 7<br/>
4: 0 1 2 3 4 5 6 7<br/>
5: 0 1 2 3 4 5 6 7<br/>
6: 0 1 2 3 4 5 6 7<br/>
7: 0 1 2 3 4 5 6 7<br/>
Cost:<br/>
0: 0 7 7 7 7 7 7 7<br/>
1: 7 0 4 4 4 4 4 4<br/>
2: 7 4 0 2 2 2 2 2<br/>
3: 7 4 2 0 2 2 2 2<br/>
4: 7 4 2 2 0 2 2 2<br/>
5: 7 4 2 2 2 0 2 2<br/>
6: 7 4 2 2 2 2 0 2<br/>
7: 7 4 2 2 2 2 2 0<br/>
Tree:<br/>
![image](https://user-images.githubusercontent.com/40664860/122538846-c79b5280-d048-11eb-9900-05eaa6b2c40a.png)<br/>
Tree Matrix:<br/>
2: 2 3 4 5 6 7 8<br/>
3: 2 3 4 5 6 7 8<br/>
4: 2 3 4 5 6 7 8<br/>
5: 2 3 4 5 6 7 8<br/>
6: 2 3 4 5 6 7 8<br/>
7: 2 3 4 5 6 7 8<br/>
8: 2 3 4 5 6 7 8<br/>
Cost:<br/>
2: 0 2 2 2 2 2 2<br/>
3: 2 0 2 2 2 2 2<br/>
4: 2 2 0 2 2 2 2<br/>
5: 2 2 2 0 2 2 2<br/>
6: 2 2 2 2 0 2 2<br/>
7: 2 2 2 2 2 0 2<br/>
8: 2 2 2 2 2 2 0<br/>
Tree:<br/>
![image](https://user-images.githubusercontent.com/40664860/122539016-f4e80080-d048-11eb-94a9-9c6ab5f5c2b5.png)<br/>
Tree Matrix:<br/>
4: 4 5 6 7 8 9<br/>
5: 4 5 6 7 8 9<br/>
6: 4 5 6 7 8 9<br/>
7: 4 5 6 7 8 9<br/>
8: 4 5 6 7 8 9<br/>
9: 4 5 6 7 8 9<br/>
Cost:<br/>
4: 0 2 2 2 2 1<br/>
5: 2 0 2 2 2 1<br/>
6: 2 2 0 2 2 1<br/>
7: 2 2 2 0 2 1<br/>
8: 2 2 2 2 0 1<br/>
9: 1 1 1 1 1 0<br/>
Tree:<br/>
![image](https://user-images.githubusercontent.com/40664860/122539251-35477e80-d049-11eb-85cb-1fe90feb7e82.png)<br/>

Distance Matrix:<br/>
6: 6 7 8 9 10<br/>
7: 6 7 8 9 10<br/>
8: 6 7 8 9 10<br/>
9: 6 7 8 9 10<br/>
10: 6 7 8 9 10<br/>
Cost:<br/>
6: 0 2 2 1 1<br/>
7: 2 0 2 1 1<br/>
8: 2 2 0 1 1<br/>
9: 1 1 1 0 <br/>
10: 1 1 1 0 0<br/>
Tree:<br/>
![image](https://user-images.githubusercontent.com/40664860/122539425-6aec6780-d049-11eb-98d5-f319f3b5f3bb.png)<br/>
Tree Matrix:<br/>
8: 8 9 10 11<br/>
9: 8 9 10 11<br/>
10: 8 9 10 11<br/>
11: 8 9 10 11<br/>
Cost:<br/>
8: 0 1 1 1<br/>
9: 1 0 0 0<br/>
10: 1 0 0 0<br/>
11: 1 0 0 0<br/>
Tree:<br/>
![image](https://user-images.githubusercontent.com/40664860/122539721-b69f1100-d049-11eb-9897-f87ea172a442.png)<br/>
Tree Matrix:<br/>
10: 10 11 12<br/>
11: 10 11 12<br/>
12: 10 11 12<br/>
Cost:<br/>
10: 0 0 0<br/>
11: 0 0 0<br/>
12: 0 0 0<br/>
Tree:<br/>
![image](https://user-images.githubusercontent.com/40664860/122540094-1b5a6b80-d04a-11eb-92ab-cdbcbfa37d29.png)<br/>
Tree matrix:<br/>
12: 12 13<br/>
13: 12 13<br/>
Cost:<br/>
12: 0 0<br/>
13: 0 0<br/>
Tree:<br/>
![image](https://user-images.githubusercontent.com/40664860/122540291-4f359100-d04a-11eb-85d5-33e5a4429e14.png)<br/>






