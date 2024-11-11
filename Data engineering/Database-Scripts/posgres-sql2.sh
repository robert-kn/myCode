# Copy the data in the file ‘web-server-access-log.txt.gz’ to a table named ‘access_log’ in the PostgreSQL database 
# {db_name}.

# The file is available at the location 

wget https://cf-courses-data.s3.us.cloud-object-storage.appdomain.cloud/IBM-DB0250EN-SkillsNetwork/labs/Bash%20Scripting/ETL%20using%20shell%20scripting/web-server-access-log.txt.gz


# decompress the gzip compressed file

gunzip web-server-access-log.txt.gz


# The following are the columns and their data types in the file:

# a. timestamp - TIMESTAMP
# b. latitude - float
# c. longitude - float
# d. visitorid - char(37)
# e. accessed_from_mobile - boolean
# f. browser_code - int

# The columns which we need to copy to the table are the first four coumns : timestamp, latitude, longitude and 
# visitorid.

# create the table in the correct database using the command after accessing the postgres database using psql client

create table access_log(timestamp TIMESTAMP, latitude float, longitude float, visitorid char(37));

# navigate back to previous terminal where you donwloaded and decompressed file 

# Create a shell script named cp-access-log.sh and add commands to complete the remaining tasks to extract and copy the data to the database.

# Extract required fields from the file.

cut -d "#" -f1,2,3,4 web-server-access-log.txt > extracted.txt

# Transform the data into CSV format.

tr "#" "," < extracted.txt > transformed.txt

# Load the data into the table access_log in PostgreSQL

echo "Loading data"

# Set the PostgreSQL password environment variable.
# Replace <yourpassword> with your actual PostgreSQL password.

export PGPASSWORD=;

# Send the instructions to connect to {db_name} and
# copy the file to the table access_log through command pipeline.
# NOTE: The file comes with a header. So use the ‘HEADER’ option in the ‘COPY’ command.

echo "\c template1;\COPY access_log  FROM '{transformed_file_path}' DELIMITERS ',' CSV HEADER;" | psql --username=postgres --host=postgres

echo "SELECT * FROM access_log;" | psql --username=postgres --host=postgres {db_name}
