Project Name: Medical Management System

Name : Nimish B Somani
MIS : 111403045

The program stores the data regarding the addition of new medicines , modifies them,
searches for a particular medicine, search for the medicines with less quantity,
and also generates a bill, checks for the daily sale and daily
profit with details.

*STOCK MANAGEMENT*
While adding a new stock, first the program checks if the record for the medicine 
already exist. If so, then the program warns you so. Else it takes the info and then 
stores it in the file.

To delete a record, the program first reads the data from the file one by one and
checks its name. If that is not to be deleted, then it copies it in a new file.
But if it is to be deleted, then it is not copied. In this way the medicines which
is to be deleted is not copied and others are. Finally the new file is then overwritten
on the previous one and then the new file is deleted.

While modifing a record, the previous medicine is deleted from the file and record is 
created with modified data.

*BILL*
While creating a bill, the program first checks if the record for the medicine name
exists. If so, then it reduces its quantity which is sold and copies the other required
data in other file named "bill.dat". Also it stores it according to date and customer
name.

While checking for the Daily sales, the program opens the file "bill.dat" and searches
for the date whose sales are to be seen. Then it stores all the bills on that date in
an array of structures and prints it at last with all the calculations.
Same is the process with Daily Profit.
