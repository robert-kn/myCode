# Let's create a DAG that runs daily, and extracts user information from /etc/passwd file, transforms it, and loads it into a file.

# This DAG will have two tasks extract that extracts fields from /etc/passwd file and transform_and_load that transforms and loads data into a file.

# import the libraries

from datetime import timedelta
# The DAG object; we'll need this to instantiate a DAG
from airflow.models import DAG
# Operators; you need this to write tasks!
from airflow.operators.bash_operator import BashOperator
# This makes scheduling easy
from airflow.utils.dates import days_ago

#defining DAG arguments

# You can override them on a per-task basis during operator initialization
default_args = {
    'owner': 'your_name_here',
    'start_date': days_ago(0),
    'email': ['your_email_here'],
    'retries': 1,
    'retry_delay': timedelta(minutes=5),
}

# defining the DAG

# define the DAG
dag = DAG(
    'my-first-dag',
    default_args=default_args,
    description='My first DAG',
    schedule_interval=timedelta(days=1),
)

# define the tasks

# define the first task

extract = BashOperator(
    task_id='extract',
    bash_command='cut -d":" -f1,3,6 /etc/passwd > /home/project/airflow/dags/extracted-data.txt',
    dag=dag,
)

# define the second task
transform_and_load = BashOperator(
    task_id='transform',
    bash_command='tr ":" "," < /home/project/airflow/dags/extracted-data.txt > /home/project/airflow/dags/transformed-data.csv',
    dag=dag,
)

# task pipeline
extract >> transform_and_load


# Submitting a DAG is as simple as copying the DAG Python file into the dags folder in the 
# AIRFLOW_HOME directory.

# Airflow searches for Python source files within the specified DAGS_FOLDER. The location of 
# DAGS_FOLDER can be located in the airflow.cfg file, where it has been configured as 
# /home/project/airflow/dags.


# Airflow will load the Python source files from this designated location. It will process 
# each file, execute its contents, and subsequently load any DAG objects present in the file.

# Therefore, when submitting a DAG, it is essential to position it within this directory 
# structure. Alternatively, the AIRFLOW_HOME directory, representing the structure 
# /home/project/airflow, can also be utilized for DAG submission.
