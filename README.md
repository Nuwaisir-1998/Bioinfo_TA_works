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


Input /Ouput:
Input:
4
0 13 21 22
13 0 12 13
21 12 0 13
22 13 13 0
The first line denotes the number of nodes(x) in the tree.The next x lines indicate the distance matrix.
step 1:
Distance matrix
0: 0 1 2 3
1: 0 1 2 3
2: 0 1 2 3
3: 0 1 2 3
Cost:
0: 0 13 21 22
1: 13 0 12 13
2: 21 12 0 13
3: 22 13 13 0
Tree:
![image](https://user-images.githubusercontent.com/40664860/122535022-f4e60180-d044-11eb-9688-f977e1d92e6d.png)
step 2:
Distance matrix:
2: 2 3 4
3: 2 3 4
4: 2 3 4
Cost:
2: 0 13 10
3: 13 0 11
4: 10 11 0
Tree:
![image](https://user-images.githubusercontent.com/40664860/122535377-5312e480-d045-11eb-8648-8612ec88a938.png
step 3:
Distance matrix:
4: 4 5
5: 4 5
Cost:
4: 0 4
5: 4 0
Tree:
![image](https://user-images.githubusercontent.com/40664860/122535515-79d11b00-d045-11eb-85a4-964b0d8d2153.png)




