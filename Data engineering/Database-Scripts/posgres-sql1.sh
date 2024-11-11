# log in to db

psql -h {host_ip} -U {db_username} -p 5432

# list databases 

\list

# connect to desired database

\connect {db_name}

# create table 

create table users(username varchar(50), userid int, homedirectory varchar(100));

# list tables in database

\dt 


# open another terminal and run the commands below

touch csv2db.sh

# This script extracts data from /etc/passwd file into a CSV file.

# The csv data file contains the user name, user id and home directory of each user account defined in /etc/passwd

# Transforms the text delimiter from ":" to ",". Loads the data from the CSV file into a table in PostgreSQL database.

# Extract phase

echo "Extracting data"

# Extract the columns 1 (user name), 3 (user id) and 6 (home directory path) from /etc/passwd

cut -d":" -f1,3,6 /etc/passwd > extracted-data.txt

# Transform phase

echo "Transforming data"

# read the extracted data and replace the colons with commas.

tr ":" "," < extracted-data.txt  > transformed-data.csv

# To load data from a shell script, you will use the psql client utility in a non-interactive manner. This is done 
# by sending the database commands through a command pipeline to psql with the help of echo command.

# PostgreSQL command to copy data from a CSV file to a table is COPY.

# The basic structure of the command which we will use in our script is:

# COPY table_name FROM 'filename' DELIMITERS 'delimiter_character' FORMAT;

# Load phase

echo "Loading data"

# Set the PostgreSQL password environment variable.
# Replace <yourpassword> with your actual PostgreSQL password.

export PGPASSWORD=;

# Send the instructions to connect to the database and copy the file to the table 'users' through command pipeline.

echo "\c {db_name}};\COPY {table_name}  FROM '{path_of_csv_file}' DELIMITERS ',' CSV;" | psql --username=postgres --host=postgres

echo "SELECT * FROM {table_name};" | psql --username=postgres --host=postgres {db_name}