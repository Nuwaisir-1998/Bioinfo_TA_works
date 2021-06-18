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
Distance matrix<br/>
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
Distance matrix<br/>
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




