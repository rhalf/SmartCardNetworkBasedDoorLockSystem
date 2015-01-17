#include <my_global.h>
#include <mysql.h>
#include <string.h>
#include <stdio.h>

MYSQL *pMysqlConnection, *pMysqlReturn;

void printError(MYSQL *pMysqlConnection) {
	fprintf(stderr, "%s\n", mysql_error(pMysqlConnection));
	mysql_close(pMysqlConnection);
	exit(1);        
}

void validateQueryArguments(char * pQuery) {
	if ((strcmp(pQuery,"select") == 0)) {
		return;
	} else if (strcmp(pQuery,"update") == 0) {
		return;
	} else if (strcmp(pQuery,"delete") == 0) {
		return;
	} else if (strcmp(pQuery,"insert") == 0) {
		return;
	} else if (strcmp(pQuery,"truncate") == 0) { 
		return;
	}
	
	printf("%s is not a query.\n", pQuery);
	exit(1);
}


int main(int argc, char *argv[]) {
	
	char * pHost = "localhost";
	char * pUserName = "root";
	char * pPassword = "raspberry";
	char * pDatabaseName = "dbSmartApp";
  
  
	char * pQuery = argv[1];
	
	
	if (pQuery == NULL) {
		printf("NULL argument 1.\n");
		exit(1);
	} 
	
	validateQueryArguments(pQuery);
	
	
	
	//Initialize Mysql
	pMysqlConnection = mysql_init(NULL);
	if (pMysqlConnection == NULL) {
		printError(pMysqlConnection);
	}

	//Connect to database
	pMysqlReturn = mysql_real_connect(
									pMysqlConnection, 
									pHost, 
									pUserName, 
									pPassword,
									pDatabaseName, 
									0, 
									NULL, 
									0);
	if ( pMysqlReturn == NULL ){
		printError(pMysqlConnection);
	}
	
	//===============================================================================
	//SELECT
	//dbSmartApp.tLogs
	//===============================================================================
	if (strcmp(pQuery,"select")==0) {
		char * pCardSerialNumber = argv[2];
		if (pCardSerialNumber == NULL) {
			printf("NULL argument 2\n");
			exit(0);
		}
		
		
		
		if (strcmp(pCardSerialNumber,"all")==0) {
			//./user select all
			int iQueryResult = mysql_query(
									pMysqlConnection, 
										"SELECT  													"
										"	dbSmartApp.tLogs.cLogsId,								"
										"	dbSmartApp.tLogs.cLogsUserId,							"
										"	dbSmartApp.tLogs.cLogsDateTime,							"	
										"	dbSmartApp.tLogs.cLogsType,								"
										"	dbSmartApp.tUser.cUserCardSerialNumber,					"
										"	dbSmartApp.tUser.cUserCardUserName,						"
										"	dbSmartApp.tUser.cUserStatus							"
										"FROM 														"
										"	dbSmartApp.tLogs										"
										"LEFT JOIN													"
										"	dbSmartApp.tUser										"
										"ON															"
										"	dbSmartApp.tLogs.cLogsUserId = dbSmartApp.tUser.cUserId;"
										);
			if (iQueryResult) {
				printError(pMysqlConnection);
			}
			
			MYSQL_RES *pMysqlResult = mysql_store_result(pMysqlConnection);
			if (pMysqlResult == NULL) {
				printError(pMysqlConnection);
			}
			
			
			int iNumberOfFields = mysql_num_fields(pMysqlResult);
						
			MYSQL_ROW pMysqlRow;
			
			while ((pMysqlRow = mysql_fetch_row(pMysqlResult))) { 
				int iIndex = 0;
				for(iIndex = 0; iIndex < iNumberOfFields; iIndex++) { 
					printf("%s\t", pMysqlRow[iIndex] ? pMysqlRow[iIndex] : "NULL"); 
				} 
				printf("\n"); 
			 }

			mysql_free_result(pMysqlResult);
			mysql_close(pMysqlConnection);

			exit(0);
			
		} else {
			//./user select cardserialnumber
			char query[256];
			memset(query,0,sizeof(query));
			
			sprintf(
						query,
						"SELECT  													"
						"	dbSmartApp.tLogs.cLogsId,								"
						"	dbSmartApp.tLogs.cLogsUserId,							"
						"	dbSmartApp.tLogs.cLogsDateTime,							"	
						"	dbSmartApp.tLogs.cLogsType,								"
						"	dbSmartApp.tUser.cUserCardSerialNumber,					"
						"	dbSmartApp.tUser.cUserCardUserName,						"
						"	dbSmartApp.tUser.cUserStatus							"
						"FROM 														"
						"	dbSmartApp.tLogs										"
						"LEFT JOIN													"
					    "	dbSmartApp.tUser										"
						"ON															"
						"	dbSmartApp.tLogs.cLogsUserId = dbSmartApp.tUser.cUserId	"
						"WHERE														"
						"	dbSmartApp.tUser.cUserCardSerialNumber='%s'				",
						pCardSerialNumber
			);
		
			
			int iQueryResult = mysql_query(
									pMysqlConnection, 
									query
									);
			if (iQueryResult) {
				printError(pMysqlConnection);
			}
			
			MYSQL_RES *pMysqlResult = mysql_store_result(pMysqlConnection);
			if (pMysqlResult == NULL) {
				printError(pMysqlConnection);
			}
			
			
			int iNumberOfFields = mysql_num_fields(pMysqlResult);
						
			MYSQL_ROW pMysqlRow;
			
			while ((pMysqlRow = mysql_fetch_row(pMysqlResult))) { 
				int iIndex = 0;
				for(iIndex = 0; iIndex < iNumberOfFields; iIndex++) { 
					printf("%s\t", pMysqlRow[iIndex] ? pMysqlRow[iIndex] : "NULL"); 
				} 
				printf("\n"); 
			 }

			mysql_free_result(pMysqlResult);
			mysql_close(pMysqlConnection);

			exit(0);
			
		}

	}
    //===============================================================================
    //Truncate
    //dbSmartApp.tUser
    //./user truncate
    //===============================================================================
    if (strcmp(pQuery,"truncate")==0) {
        
        //./user insert cardserialnumber
        
        int iQueryResult = mysql_query(
                                       pMysqlConnection,
                                       "TRUNCATE dbSmartApp.tLogs;"
                                       );
        if (iQueryResult) {
            printError(pMysqlConnection);
        }
      
        mysql_close(pMysqlConnection);
        printf("Ok!\n");
        exit(0);
    }
	//===============================================================================
	//Insert
	//dbSmartApp.tLogs
	//===============================================================================
	if (strcmp(pQuery,"insert")==0) {
		
		char * pCardSerialNumber = argv[2];
		char * pDateTime		 = argv[3];
		char * pLogType			 = argv[4];
		
		if (pCardSerialNumber == NULL) {
			printf("NULL argument 2\n");
			exit(0);
		}
		
		if (pDateTime == NULL) {
			printf("NULL argument 3\n");
			exit(0);
		}
		
		if (pLogType == NULL) {
			printf("NULL argument 4\n");
			exit(0);
		}
		
		//---------------------------------------------------------------------------------------
		//./logs select cardserialnumber
		//---------------------------------------------------------------------------------------
		char query[256];
		memset(query,0,sizeof(query));
		
		sprintf(
					query,
					"SELECT 																	"
					"	dbSmartApp.tUser.cUserId																		"
                    "FROM 																		"
					"	dbSmartApp.tUser														"
                    "WHERE 																		"
					"	dbSmartApp.tUser.cUserCardSerialNumber = '%s'							",				
					pCardSerialNumber
		);
	
		int iQueryResult = mysql_query(
								pMysqlConnection, 
								query
								);
		if (iQueryResult) {
			printError(pMysqlConnection);
		}

		MYSQL_RES *pMysqlResult = mysql_store_result(pMysqlConnection);
		if (pMysqlResult == NULL) {
			printError(pMysqlConnection);
		}
		
		
		int iNumberOfFields = mysql_num_fields(pMysqlResult);
					
		MYSQL_ROW pMysqlRow;
		
		pMysqlRow = mysql_fetch_row(pMysqlResult);
	
		char * pUserId = pMysqlRow[0];
		
		//---------------------------------------------------------------------------------------
		//./logs insert cardserialnumber
		//---------------------------------------------------------------------------------------
		memset(query,0,sizeof(query));
		
		sprintf(
					query,
					"INSERT																		"
				    "INTO dbSmartApp.tLogs(cLogsUserId, cLogsDateTime, cLogsType)				"
				    "VALUES ('%s','%s','%s')													",				
					pUserId,
					pDateTime,
					pLogType
					
		);
	
		iQueryResult = mysql_query(
								pMysqlConnection, 
								query
								);
		if (iQueryResult) {
			printError(pMysqlConnection);
		}
		
		mysql_free_result(pMysqlResult);
		mysql_close(pMysqlConnection);

		printf("Ok!");
		exit(0);
	}
	
	mysql_close(pMysqlConnection);
	exit(1);
}