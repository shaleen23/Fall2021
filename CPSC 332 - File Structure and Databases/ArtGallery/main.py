import mysql.connector #import the MYSQL Connector library into python

from tabulate import TableFormat, tabulate #import the tabulate library, which formats the mysql output as a proper table


ArtGallery = mysql.connector.connect(user='root', password='shaleen23', host='127.0.0.1', database='ArtGallery') #connect the ArtGallery Database

mycursor = ArtGallery.cursor() #iterate through tables

mycursor.execute("SELECT * FROM Artist") #get all the data from the Artist table
myresult1 = mycursor.fetchall() #store all the data from the Artist table in the myresult1 variable

mycursor.execute("SELECT * FROM ArtShows") #get all the data from the ArtShows table
myresult2 = mycursor.fetchall() #store all the data from the ArtShows table in the myresult2 variable

mycursor.execute("SELECT * FROM ArtWork") #get all the data from the ArtWork table
myresult3 = mycursor.fetchall() #store all the data from the ArtWork table in the myresult3 variable


mycursor.execute("SELECT * FROM Customer") #get all the data from the Customer table
myresult4 = mycursor.fetchall() #store all the data from the Customer table in the myresult4 variable


mycursor.execute("SELECT * FROM Customer_has_ArtShows") #get all the data from the Customer_has_ArtShows table
myresult5 = mycursor.fetchall() #store all the data from the Customer_has_ArtShows table in the myresult5 variable


checkTable = True #bool condition will be used in the userInput
artQuery = ("SELECT StyleOfArt FROM Artist") #gets all the styles of art by the artist in the artist table
nameQuery = ("SELECT Name FROM Artist") #gets all the names of the artist in the artist table
mycursor.execute(nameQuery)

records = mycursor.fetchall() #store all the art styles in the records variable
mycursor.execute(artQuery)
records2 = mycursor.fetchall() #store all the names in the records2 variable

for x,  y in zip(records, records2): #for loop iterates through records and records2, and then prints each index
    print("ArtistName: {}, StyleOfArt: {}".format(x,y))

print("\n")


while checkTable: #while the checkTable variable is true, do the following
    userInput = input("Enter which table you want to display:\n\n1.Arist\n\n2.ArtShows\n\n3.ArtWork\n\n4.Customer\n\n5.Customer_has_ArtShows\n\n") #get the userInput of which table record they want to see
    print('\n')
    if userInput == '1': #if the user wants to see the Artist table...
        print(tabulate(myresult1, headers=['Name', 'Phone', 'Address', 'Age', 'StyleOfArt', 'BirthPlace'], tablefmt='psql')) #the artist table will be printed using the tabulate function
        print('\n')
    elif userInput == '2':  #if the user wants to see the ArtShows table...
        print(tabulate(myresult2, headers=['ShowID', 'DateTime', 'Location', 'contactPerson', 'contactNumber', 'Artist_Name'], tablefmt='psql')) #the ArtShows table will be printed using the tabulate function
        print('\n')
    elif userInput == '3':  #if the user wants to see the ArtWork table...
        print(tabulate(myresult3, headers=['Title', 'Location', 'Price', 'DateAcquired', 'DateOfCreation', 'TypeOfArt', 'Artist_Name'], tablefmt='psql')) #the ArtWork table will be printed using the tabulate function
        print('\n')
    elif userInput == '4':  #if the user wants to see the Customer table...
        print(tabulate(myresult4, headers=['CustomerNumber', 'Phone', 'ArtPreference'], tablefmt='psql')) #the Customer table will be printed using the tabulate function
        print('\n')
    elif userInput == '5':  #if the user wants to see the Customer_has_ArtShows table...
        print(tabulate(myresult5, headers=['Customer_CustomerNumber', 'ArtShows_ShowID'], tablefmt='psql')) #the Customer_has_ArtShows table will be printed using the tabulate function
        print('\n')
    userInput2 = input("Would you like to view another table? Type Yes or No\n\n") #ask the user if they want to see another table
    print('\n')
    if userInput2 == "No": #if they say no...
        checkTable = False #set the checkTable variable to false and exit the program 
        print("Thank you for checking out the Art Gallery! Come back soon") 

