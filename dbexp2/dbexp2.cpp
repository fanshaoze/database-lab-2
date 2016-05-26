// dbexp2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main(int argc, char * argv[])
{

	int i;
    //for (i=0; i < argc; i++)
//        printf("Argument %d is %s.\n", i, argv[i]);
	//cout<<argv[5]<<endl;
	BOOL continue_or_not = TRUE;
	int number;
	string para1;
	string para2;
	const char *s;
	string command;
	string con1;
	string con2;
	string con3;
	string con4;
	string con5;
    MYSQL mysql_conn; /* Connection handle */
    MYSQL_RES *mysql_result = NULL; /* Result handle */
	do
	{
		if (mysql_init(&mysql_conn) != NULL) 
		{
			if (mysql_real_connect(&mysql_conn, "localhost", "root", "root", "company", MYSQL_PORT, NULL, 0) != NULL)
			{

				//cout<<" "<<charpara<<endl;
				number = 1;
				//cout<<number<<" "<<endl;
				//number = 0;
				switch (number)
				{
					case 1:
					{
						con1 =  "select employee.essn from employee,works_on,project "
								"where employee.essn = works_on.ESSN AND "
								"works_on.PNO = project.PNO AND "
								"project.PNO = '";
						//con2 = argv[5];
						con2 = "p1";
						con3 = "'";
						command = con1+con2+con3;
						cout<<command<<endl;
						mysql_query(&mysql_conn, "set names 'gbk'");
						mysql_result = new MYSQL_RES;
						continue_or_not = mathod(&mysql_conn,mysql_result,command);
						break;
					}
					case 2:
					{
						con1 = "select ename from employee,works_on,project "
								"where employee.essn = works_on.ESSN AND "
								"works_on.PNO = project.PNO AND "
								"project.PNAME = '";
						con2 = argv[5];
						//con2 = "SQLProject";
						con3 = "'";
						command = con1+con2+con3;
						cout<<command<<endl;
						mysql_query(&mysql_conn, "set names 'gbk'");
						mysql_result = new MYSQL_RES;
						continue_or_not = mathod(&mysql_conn,mysql_result,command);
						break;
					}
					case 3:
					{
						con1 = "select ENAME,ADDRESS "
								"from employee,department " 
								"where employee.DNO=department.DNO "
								"and department.DNAME='";
						con2 = argv[5];
						//con2 = "研发部";
						con3 = "'";
						command = con1+con2+con3;
						cout<<command<<endl;
						mysql_query(&mysql_conn, "set names 'gbk'");
						mysql_result = new MYSQL_RES;
						continue_or_not = mathod(&mysql_conn,mysql_result,command);
						break;
					}
					case 4:
					{
						con1 = "select ENAME,ADDRESS "
								"from employee,department " 
								"where employee.DNO=department.DNO "
								"and department.DNAME='";
						con2 = argv[5];
						con3 = "' and salary<";
						con4 =  argv[6];
						
						command = con1+con2+con3+con4;
						cout<<command<<endl;
						mysql_query(&mysql_conn, "set names 'gbk'");
						mysql_result = new MYSQL_RES;
						continue_or_not = mathod(&mysql_conn,mysql_result,command);
						break;
					}
					case 5:
					{
						con1 = "select ENAME from employee "
								"where ENAME "  
								"NOT IN (select ENAME from employee,works_on "
								"where employee.ESSN=works_on.ESSN and works_on.PNO='";
						con2 = argv[5];
						con3 = "')";
						command = con1+con2+con3;
						cout<<command<<endl;
						mysql_query(&mysql_conn, "set names 'gbk'");
						mysql_result = new MYSQL_RES;
						continue_or_not = mathod(&mysql_conn,mysql_result,command);
						break;
					}
					case 6:
					{
						con1 = "select ename,dname "
								"from employee NATURAL JOIN " 
								"department where superssn = "
								"(select essn from employee where ename = '";
						con2 = argv[5];
						con3 = "')";
						command = con1+con2+con3;
						cout<<command<<endl;
						mysql_query(&mysql_conn, "set names 'gbk'");
						mysql_result = new MYSQL_RES;
						continue_or_not = mathod(&mysql_conn,mysql_result,command);
						break;
					}
					case 7:
					{
						con1 = "select ESSN from works_on where works_on.PNO='";
						con2 = argv[5];
						con3 = "' and works_on.ESSN in  (select ESSN from works_on where works_on.PNO='";
						con4 =  argv[6];
						con5 ="')";
						command = con1+con2+con3+con4+con5;
						cout<<command<<endl;
						mysql_query(&mysql_conn, "set names 'gbk'");
						mysql_result = new MYSQL_RES;
						continue_or_not = mathod(&mysql_conn,mysql_result,command);
						break;
					}
					case 8:
					{
						con1 = "select DNAME "
							"from employee,department "
							"where employee.DNO=department.DNO "
							"group by department.DNO having avg(SALARY)<";
						con2 = argv[5];
						
						command = con1+con2;
						cout<<command<<endl;
						mysql_query(&mysql_conn, "set names 'gbk'");
						mysql_result = new MYSQL_RES;
						continue_or_not = mathod(&mysql_conn,mysql_result,command);
						break;
					}
					case 9:
					{
						con1 = "select ENAME,sum(works_on.HOURS) "
								"from works_on,employee "
								"where works_on.ESSN=employee.ESSN "
								"group by employee.ESSN having count(*)>=";
						con2 = argv[5];
						con3 = " and sum(works_on.HOURS)<";
						con4 =  argv[6];
					
						command = con1+con2+con3+con4;
						cout<<command<<endl;
						mysql_query(&mysql_conn, "set names 'gbk'");
						mysql_result = new MYSQL_RES;
						continue_or_not = mathod(&mysql_conn,mysql_result,command);
						break;
					}
					default:
						break;
				}
			} 
			else 
			{
        		i = mysql_errno(&mysql_conn);
        		s = mysql_error(&mysql_conn);
				printf("Connection fails(ERROR %d): %s\n", i, s);
				mysql_free_result(mysql_result);
				mysql_close(&mysql_conn);
				break;
			}
		} 
		else 
		{
			printf("Initialization fails\n");
			break;
		}

	}while(continue_or_not);
    return 0;
}
/*
				cout<< "input the search number and the parameters you want by using : company_query –q <Number> -p [Parameters]"<<endl;
				//company_query –q <Number> -p [Parameters]
				cin.getline(command,256);
				cout<<command<<endl;
				for (i = 0;i<100;i++)
				{
					//cout<<"error"<<command[i]<<endl;
					if (command[i] == '<')
					{
						numberchar[0] = command[i+1];
						//cout<<numberchar<<"e"<<endl;
						number = atof(numberchar);
						//cout<<"number"<<number<<endl;
						//cout<<number;
					}
					else if(command[i] == '[')
					{
						for (j = i+1;j<100;j++)
						{
							if(command[j] != ']')
							{
								charpara[j-(i+1)] = command[j]; 
							}
							else 
							{
								charpara[j-(i+1)] = '\0';
								break;
							}
							
						}
						//cout<<charpara<<endl;
						//cout<<charpara;

					}
				}
*/

/*

int _tmain(int argc, _TCHAR* argv[])
{
	int i;
	const char *s;
    MYSQL mysql_conn; // Connection handle 
    MYSQL_RES *mysql_result = NULL; // Result handle 
    MYSQL_ROW mysql_row; // Row data 
    int f1, f2, num_row, num_col;

    if (mysql_init(&mysql_conn) != NULL) 
	{
        if (mysql_real_connect(&mysql_conn, "localhost", "root", "root", "company", MYSQL_PORT, NULL, 0) != NULL)
		{
			mysql_query(&mysql_conn, "set names 'gbk'");
            if (mysql_query(&mysql_conn, "select * from employee") == 0) 
			{
				mysql_result = new MYSQL_RES;
                mysql_result = mysql_store_result(&mysql_conn);
                num_row = mysql_num_rows(mysql_result);
                num_col = mysql_num_fields(mysql_result);
 
                for (f1 = 0; f1 < num_row; f1++) 
				{
                    mysql_row = mysql_fetch_row(mysql_result);
                    for (f2 = 0; f2 < num_col; f2++)
                        printf("[Row %d, Col %d] ==> [%s]\n", f1+1, f2+1, mysql_row[f2]);
                }
            } 
			else printf("Query fails\n");
        } 
		else 
		{
        	i = mysql_errno(&mysql_conn);
        	s = mysql_error(&mysql_conn);
            printf("Connection fails(ERROR %d): %s\n", i, s);
        }
    } 
	else printf("Initialization fails\n");
    mysql_free_result(mysql_result);
    mysql_close(&mysql_conn);
    return 0;
}*/

/*
	MYSQL mysql_conn;  Connection handle 

    if (mysql_init(&mysql_conn) != NULL) 
	{
        if (mysql_real_connect(&mysql_conn, "localhost", "root","root", "company", MYSQL_PORT, NULL, 0) != NULL)
            printf("GOOD!\n");
        else
            printf("Connection fails.\n");
    } 
	else
	{
        printf("Initialization fails.\n");
        return -1;
    }

    mysql_close(&mysql_conn);*/

