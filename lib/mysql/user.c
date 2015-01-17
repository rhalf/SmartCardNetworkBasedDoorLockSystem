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
    } else if (strcmp(pQuery,"sInsert") == 0) {
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
	//dbSmartApp.tUser
	//./user select cardserialnumber
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
									"SELECT 										"
									"	* 											"
									"FROM 											"
									"	dbSmartApp.tUser							"
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
			char query[512];
			memset(query,0,sizeof(query));
			
			sprintf(
						query,
						"SELECT * 											"
						"FROM 												"
						"	dbSmartApp.tUser								"
						"WHERE												"
						"	dbSmartApp.tUser.cUserCardSerialNumber = '%s'	",
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
	//Insert
	//dbSmartApp.tUser
	//./user insert casdserial cardusername
	//===============================================================================
	if (strcmp(pQuery,"insert")==0) {
		char * pCardSerialNumber = argv[2];
		char * pCardUserName = argv[3];
		
		if (pCardSerialNumber == NULL) {
			printf("NULL argument 2\n");
			exit(0);
		}
		
		//./user insert cardserialnumber
		char query[512];
		memset(query,0,sizeof(query));
		
		sprintf(
					query,
					"INSERT																			"
				    "INTO dbSmartApp.tUser (cUserCardSerialNumber, cUserCardUserName, cUserStatus)	"
				    "VALUES ('%s','%s','%s')",	
					pCardSerialNumber,
					pCardUserName,
					"Restricted"
		);
	
		
		int iQueryResult = mysql_query(
								pMysqlConnection, 
								query
								);
		if (iQueryResult) {
			printError(pMysqlConnection);
		}

		mysql_close(pMysqlConnection);
		printf("Ok!\n");
		exit(0);
	}
    //===============================================================================
    //sInsert
    //dbSmartApp.tUser
    //./user insert casdserial cardusername
    //===============================================================================
    if (strcmp(pQuery,"sInsert")==0) {
        char * pCardSerialNumber = argv[2];
        char * pCardUserName = argv[3];
        char * pCardStatus = argv[4];
        
        if (pCardSerialNumber == NULL) {
            printf("NULL argument 2\n");
            exit(0);
        }
        
        if (pCardUserName == NULL) {
            printf("NULL argument 3\n");
            exit(0);
        }
        
        if (pCardStatus == NULL) {
            printf("NULL argument 4\n");
            exit(0);
        }

        
        //./user insert cardserialnumber
        char query[512];
        memset(query,0,sizeof(query));
        
        sprintf(
                query,
                "CALL dbSmartApp.addUser('%s','%s','%s')",
                pCardSerialNumber,
                pCardUserName,
                pCardStatus
                );
        
        
        int iQueryResult = mysql_query(
                                       pMysqlConnection, 
                                       query
                                       );
        if (iQueryResult) {
            printError(pMysqlConnection);
        }
        
        mysql_close(pMysqlConnection);
        printf("Ok!\n");
        exit(0);
    }
    //===============================================================================
    //Truncate
    //dbSmartApp.tUser
    //./user truncate
    //===============================================================================
    if (strcmp(pQuery,"truncate")==0) {
        
        //./user insert cardserialnumber
        char query[512];
        memset(query,0,sizeof(query));
        
        sprintf(
                query,
                "TRUNCATE dbSmartApp.tUser"
                );
        
        
        int iQueryResult = mysql_query(
                                       pMysqlConnection,
                                       query
                                       );
        if (iQueryResult) {
            printError(pMysqlConnection);
        }
        
        mysql_close(pMysqlConnection);
        printf("Ok!\n");
        exit(0);
    }
	//===============================================================================
	//Update
	//dbSmartApp.tUser
	//./user update casdserialold cardserialnew cardusernamenew statusnew
	//===============================================================================
	if (strcmp(pQuery,"update")==0) {
		char * pCardSerialNumber = argv[2];
		char * pCardSerialNumberNew = argv[3];
		char * pCardUserName = argv[4];
		char * pStatus = argv[5];
		
		if (pCardSerialNumber == NULL) {
			printf("NULL argument 2\n");
			exit(0);
		}
		if (pCardSerialNumberNew == NULL) {
			printf("NULL argument 3\n");
			exit(0);
		}
		if (pCardUserName == NULL) {
			printf("NULL argument 4\n");
			exit(0);
		}
		if (pStatus == NULL) {
			printf("NULL argument 5\n");
			exit(0);
		}
		
		
		//./user uodate cardserialnumber
		char query[512];
		memset(query,0,sizeof(query));
		sprintf(
				query,
				"SET @id = (											"
				"	SELECT dbSmartApp.tUser.cUserId 					"
				"	FROM dbSmartApp.tUser								"
				"	WHERE dbSmartApp.tUser.cUserCardSerialNumber = '%s'	"
				"	LIMIT 1												"
				");														",											
				pCardSerialNumber	
		);
		
		int iQueryResult = mysql_query(
								pMysqlConnection, 
								query
								);
		if (iQueryResult) {
			printError(pMysqlConnection);
		}

		memset(query,0,sizeof(query));
		sprintf(
				query,
				"UPDATE dbSmartApp.tUser								"
				"SET 													"
				"	dbSmartApp.tUser.cUserCardSerialNumber = '%s',		"
				"	dbSmartApp.tUser.cUserCardUserName = '%s',			"
				"	dbSmartApp.tUser.cUserStatus = '%s'					"
				"WHERE													"
				"	dbSmartApp.tUser.cUserId = @id;						",																
				pCardSerialNumberNew,
				pCardUserName,
				pStatus				
		);
		
		iQueryResult = mysql_query(
								pMysqlConnection, 
								query
								);
		if (iQueryResult) {
			printError(pMysqlConnection);
		}
		
		mysql_close(pMysqlConnection);
		printf("Ok!\n");
		exit(0);
	}
	
	mysql_close(pMysqlConnection);
	exit(1);
}