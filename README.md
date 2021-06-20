# Bioinfo_TA_works

## Neighbor Joining Algorithm (NJ)

  

### Problem:

Reconstruct the evolutionary tree given the distance matrix.

  

### How to Run The Code:

Go to the NJ folder. Put the input in **in.txt** file. The first line of the input file denotes the number of rows and columns of the distance matrix. Each of the next *n* lines contains *n* space seperated numbers denoting an element of the distance matrix.
Open a terminal there. Then run the follwing command.
```
./main.sh
```
Make sure to have the execution permission by running:
```
chmod +x main.sh
```

### Example 1

#### Input:
```
4
0 13 21 22
13 0 12 13
21 12 0 13
22 13 13 0
```

##### Step 1:
Tree matrix
```
0: 0 1 2 3
1: 0 1 2 3
2: 0 1 2 3
3: 0 1 2 3
```
Cost:
```
0: 0 13 21 22
1: 13 0 12 13
2: 21 12 0 1
3: 22 13 13 0
```
Tree:

![image](https://user-images.githubusercontent.com/40664860/122535022-f4e60180-d044-11eb-9688-f977e1d92e6d.png)

##### Step 2:

Tree matrix
```
2: 2 3 4
3: 2 3 4
4: 2 3 4
```
Cost:
```
2: 0 13 10
3: 13 0 11
4: 10 11 0
```
Tree:

![image](https://user-images.githubusercontent.com/40664860/122535377-5312e480-d045-11eb-8648-8612ec88a938.png)

##### Step 3:

Distance matrix:
```
4: 4 5
5: 4 5
```
Cost:
```
4: 0 4
5: 4 0
```
Tree:

![image](https://user-images.githubusercontent.com/40664860/122535515-79d11b00-d045-11eb-85a4-964b0d8d2153.png)

#### Example 2:
#### Input:
```
8
0 7 7 7 7 7 7 7
7 0 4 4 4 4 4 4
7 4 0 2 2 2 2 2
7 4 2 0 2 2 2 2
7 4 2 2 0 2 2 2
7 4 2 2 2 0 2 2
7 4 2 2 2 2 0 2
7 4 2 2 2 2 2 0
```
##### Step 1:
Tree Matrix:
```
0: 0 1 2 3 4 5 6 7
1: 0 1 2 3 4 5 6 7
2: 0 1 2 3 4 5 6 7
3: 0 1 2 3 4 5 6 7
4: 0 1 2 3 4 5 6 7
5: 0 1 2 3 4 5 6 7
6: 0 1 2 3 4 5 6 7
7: 0 1 2 3 4 5 6 7
```
Cost:
```
0: 0 7 7 7 7 7 7 7
1: 7 0 4 4 4 4 4 4
2: 7 4 0 2 2 2 2 2
3: 7 4 2 0 2 2 2 2
4: 7 4 2 2 0 2 2 2
5: 7 4 2 2 2 0 2 2
6: 7 4 2 2 2 2 0 2
7: 7 4 2 2 2 2 2 0
```
Tree:

![image](https://user-images.githubusercontent.com/40664860/122538846-c79b5280-d048-11eb-9900-05eaa6b2c40a.png)

Tree Matrix:
```
2: 2 3 4 5 6 7 8
3: 2 3 4 5 6 7 8
4: 2 3 4 5 6 7 8
5: 2 3 4 5 6 7 8
6: 2 3 4 5 6 7 8
7: 2 3 4 5 6 7 8
8: 2 3 4 5 6 7 8
```
Cost:
```
2: 0 2 2 2 2 2 2
3: 2 0 2 2 2 2 2
4: 2 2 0 2 2 2 2
5: 2 2 2 0 2 2 2
6: 2 2 2 2 0 2 2
7: 2 2 2 2 2 0 2
8: 2 2 2 2 2 2 0
```
Tree:

![image](https://user-images.githubusercontent.com/40664860/122668556-7622cd00-d1da-11eb-9fc4-7e7b650e7c5f.png)


Tree Matrix:
```
4: 4 5 6 7 8 
5: 4 5 6 7 8 9
6: 4 5 6 7 8 
7: 4 5 6 7 8 
8: 4 5 6 7 8 
9: 4 5 6 7 8 9
```
Cost:
```
4: 0 2 2 2 2 1
5: 2 0 2 2 2 1
6: 2 2 0 2 2 1
7: 2 2 2 0 2 1
8: 2 2 2 2 0 1
9: 1 1 1 1 1 0
```
Tree:

![image](https://user-images.githubusercontent.com/40664860/122669351-b97f3a80-d1de-11eb-8ca2-c55b064ab312.png)


Distance Matrix:<br/>
```
6: 6 7 8 9 10
7: 6 7 8 9 10
8: 6 7 8 9 10
9: 6 7 8 9 10
10: 6 7 8 9 10
```
Cost:
```
6: 0 2 2 1 1
7: 2 0 2 1 1
8: 2 2 0 1 1
9: 1 1 1 0 
10: 1 1 1 0 0
```
Tree:

![image](https://user-images.githubusercontent.com/40664860/122668761-78d1f200-d1db-11eb-88ff-51f9ee4bc17c.png)



Tree Matrix:
```
8: 8 9 10 11
9: 8 9 10 11
10: 8 9 10 11
11: 8 9 10 11
```
Cost:<br/>
```
8: 0 1 1 1
9: 1 0 0 0
10: 1 0 0 0
11: 1 0 0 0
```
Tree:

![image](https://user-images.githubusercontent.com/40664860/122669170-e97a0e00-d1dd-11eb-80fd-4a7f6c4c963d.png)

Tree Matrix:<br/>
```
10: 10 11 12
11: 10 11 12
12: 10 11 12
```
Cost:
```
10: 0 0 0
11: 0 0 0
12: 0 0 0
```
Tree:<br/>



Tree matrix:
```
12: 12 13
13: 12 13
```
Cost:
```
12: 0 0
13: 0 0
```
Tree:

![image](https://user-images.githubusercontent.com/40664860/122669278-65745600-d1de-11eb-8810-0251699815ff.png)

