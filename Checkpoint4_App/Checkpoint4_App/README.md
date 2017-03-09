# How to Use the Application

When the executable is run, select an action from the following prompt:

```
 Select an action:
     1: Get information on a user
     2: Get information on a business
     3: Combine information.
     4: Get summary information of a user.
     5: Get summary information on a business.
     6: Get active users (high review count)
     0: Quit
 Enter your number:
```

Further details about each option are below.

## (1./2.) Get information on a user/business

```
Enter the name of the user you want to know about:
```
or
``` 
Enter the name of the business you want to know about: 
```

When a user/business is entered, a query is sent to print a table with all information on that user or business located in the Yelp user or business dataset.

## (3.) Combine information

```
Enter the name of a user whose reviews you would like to know about:
```
This combines the user dataset and business dataset to display a table with a user's review information.

## (4./5.) Get summary information of a user/business

```
Enter the name of a user who you would like to see the summary for:
```
or
```
Enter the name of a business who you would like to see the summary for:
```

This performs the same functionality as options (1.) and (2.), but includes more information about a user or business.

## (6.) Get active users (high review count)



# Functionalities

## Reading in JSON data and entering it into DB system

A new table is created by calling the createTableFromJson(char\*) function.

```c++
Table createTableFromJson(char* filename);
```

This function parses through a json file and imports the data into a Table.

## Use of DB system to retrieve data for display in application

A query function is used to send a query to the database and return a new table for displaying. For example:

```c++
queryTable = db.query("user_id, name, review_count", <table object>, "name = <user_input>");
```

This creates a new table with headings "user_id," "name," and "review_count," and the query looks for records in the given table object where name = \<user_input\>, in this case.

## Providing information about users

Option (1.) in the application displays a table with user information. This table is created by using a query function where the user's name in the user dataset is equal to the name user input.

## Providing information about businesses

Option (2.) in the application displays a table with business information. This table is created by using a query function where the business name is equal to the name user input.

## Combining information from more than one table in the display

Option (3.) performs this functionality by creating a table with a user's name and review count, then creating another table from finding the business_id in the first table.

## Overall level of features in the program (beyond the minimum)

Options (4.) and (5.) list further information about a user or business. 
Option (6.) returns the average rating of a business.
