# Searching for shelter in the flood

<p> During the country's affectation by a tropical storm, the Comisión Nacional de Emergencias compiled information on the condition of the area, identifying the flooded areas and the areas that have remained above the water level.

To contribute to the emergency response, the Universidad de Costa Rica has asked students from the Escuela de Ciencias de la Computación e Informática to develop a system for identifying suitable areas to establish shelters. These should be located in the largest unaffected areas so that if the water level rises again, the shelters will remain safe.

There are currently satellite images marked by the CNE of large tracts of land, which is why a subroutine in C is required to receive a rectangular piece of land and indicate the suitable areas to establish a refuge.

To make sure that the subroutine does its job correctly, the team prepared some test cases. You must, in addition to the subroutine, write a program that tests it against the prepared cases. The data provided by the CNE consists in the entry of the dimensions of the land in rows and columns, followed by a sketch of the rectangular floor, where a capital X (X) represents a flooded area and a hyphen (-) indicates an area that is flooded. has remained above the water level.</p>
#

<b> Input:</b>

```
5 8

XXX-XXXX
XX--XXXX
-XXXXX--
-XXX----
XXXXXX--
```

<b> Output:</b>

```
1
XXX-XXXX
XX--XXXX
-XXXXXRR
-XXXRRRR
XXXXXXRR
```

<p> 

For the CNE, it would be convenient for the subroutine to receive the land as a matrix and in it mark with a capital “r” (R) the cells belonging to the area where the refuge will be established. These will be all the zones belonging to the largest unflooded area. Two cells are considered part of the same zone if they are contiguous vertically or horizontally. It may happen that two or more zones are the same size. In this case, all must be marked in the matrix. The number of zones found must also be indicated on the first line of the start.

The test program must read the data to use. These can come from standard input or from a file. In case you want to use a file, its name will be provided on the standard input. Because the files can be very large, you can include a -b parameter indicating that the file is binary. In case it is a binary file, the format will be as follows:</p>



<table>
    <tr> 
        <td>Element</td>
        <td>Size</td>
    </tr>

<tr> 
    <td>Rows amount</td>
    <td>4 bytes unsigned</td>
</tr>

<tr> 
    <td>Columns amount</td>
    <td>4 bytes unsigned</td>
</tr>

<tr> 
    <td>Continious data matix</td>
    <td>Rows * colunms bytes</td>
</tr>

</table>



<p> 
Regardless of whether the input is provided in a binary file, the output must be generated in a text file. The test program should call the subroutine and print on the output the number of zones found and the resulting terrain with the marked zones. If the input was provided in a file, the output should also be a file, with the same name, appending the text “-out” to the file name. Otherwise, the output will need to be displayed on stdout.
</p>

<br>
<br>
<br>

# Algorithm design

## General description
    
To solve the problem, we have designed a subroutine that receives a memory address to a character array with <b>r</b> rows and <b>c</b> columns. The values ​​of the matrix must be previously validated so that they contain only the values ​​(X) and (-).

Next, the matrix is cloned to apply the algorithm <a href="https://github.com/adrianblade/java-algorithm#:~:text=A%20Search%20in%20depth%20(in,way% 20ordered%2C%20but%20not%20uniform.">DFS</a>, going through each node (box) of the same, verifying if it is safe terrain or not. Finally, the size of safe terrain found and the coordinates of any of them are saved. their nodes.

<img src="https://res.cloudinary.com/djiafuqdd/image/upload/v1682837381/Diagrama_de_flujo_dsazts.png" alt='Diagrama de flujo completo'>

<br>
<br>
<br>


## Specific description
<br>


## Safe area search (1)

<br>

### 1.1 Matrix clone
Knowing the dimensions of the matrix, with the help of a for loop, an exact copy of it is traversed and created so as not to alter the original, since it is necessary to print the results. This clone can have the following values

<table>
    <tr> 
        <td>Value</td>
        <td>Meaning</td>
    </tr>

<tr> 
    <td>X</td>
    <td>Flood</td>
</tr>

<tr> 
    <td>-</td>
    <td>Safe Area</td>
</tr>

<tr> 
    <td>C</td>
    <td>Checked zone</td>
</tr>

</table>

<br>
<br>
<br>

### 1.2 Structs array

An array of struct pointers is created to store the information of all the safe areas found. Each struct has the following information:

<table>
    <tr> 
        <td>Atribute</td>
        <td>Meaning</td>
    </tr>

<tr> 
    <td>Row</td>
    <td>Row cordenate of one cell of the area</td>
</tr>

<tr> 
    <td>Col</td>
    <td>Column cordenate of one cell of the area</td>
</tr>

<tr> 
    <td>Size</td>
    <td>Total safe area size </td>
</tr>

</table>

<br>
<br>

### 1.3 Matrix clone iterarion

With the help of a for loop again, the matrix is ​​traversed in search of a cell with the value of Safe Area (-). If the current box does not correspond to (-) it changes it to (c), implying that it has already been reviewed; otherwise, it creates a struc (point 1.2), then it applies the DFS algorithm explained in point 1.4 and once finished save this struct in the array (point 1.2) and continue with the iteration
<br>
<br>

### 1.4 DFS

If the current cell corresponds to (-) it will mark it as checked (c), it will increase the Size in the struct, it will store the coordinates in the row and col fields of the struct. Then check the neighboring squares with the following algorithm

```
Up: Row - 1
Down: Row + 1
Left: Row - 1
Right: Row + 1
```

If any of the boxes found is the previous search is (-) repeat this same algorithm (1.4) in said box.


## Indentify safe Area

## 2.1 Comparing areas 

The array of structs is traversed looking for the one with the largest area.

## 2.2 Mark biggets safe area

Once the larger areas (in case there are two areas with the same size) are identified, a DFS algorithm similar to point 1.4 is executed, which, taking the col and row fields of the struct, replaces the area marked by R





