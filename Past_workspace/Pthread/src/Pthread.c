/*
 ============================================================================
 Name        : Pthread.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_main(void* message){
	printf("%s\n",(const  char*)message);
	return message;
}

int main(void) {
	pthread_t thread1,thread2;
	const char* message1= "Thing1";	// const는 가리키고 있는 값을 변경할 수 없다.
	const char* message2= "Thing2";	// 가리키는 대상은 바꿀 수 있다.
	// char* const message3 ="Thing3";	// 가리키는 대상을 바꿀 수 없다.

//	char * test="test_message";
	//이 함수가 실행되면 스레드가 켜지고 아래로 넘어간다.
	pthread_create(&thread1, NULL, thread_main,(void*)message1);//pthread_t 변수,?,실행할 함수,파라미터

	pthread_create(&thread2, NULL, thread_main,(void*)message2);
	//pthread_create(&thread2, NULL, thread_main,&test);	// 다른 주소가 됨. thread_main을 char*로 바꿔도 같다.

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	return EXIT_SUCCESS;
}
