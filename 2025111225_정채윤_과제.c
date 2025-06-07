//일기장 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "2025111225_정채윤_과제.h"

void write_diary() {
	char date[9];	//날짜 입력
	char filename[32];	//파일 이름 저장
	char content[1000];	//일기 내용 입력

	//날짜 입력
	printf("날짜를 입력하세요 (YYYYMMDD): ");	
	scanf("%s", date);
	getchar();

	//파일 이름 생성
	snprintf(filename, sizeof(filename), "diary_%s.txt", date);

	printf("일기 내용을 입력하세요 (종료하려면 Enter를 두 번 누르세요): \n");
	FILE* fp = fopen(filename, "w");
	if (!fp) {
		printf("파일 열기 실패\n");
		return;
	}

	//일기 내용 입력받기
	while (1) {
		fgets(content, sizeof(content), stdin);
		if (strcmp(content, "\n") == 0)
			break;
		fputs(content, fp);	//파일에 저장
	}

	fclose(fp);	//파일 닫기
	printf("저장 완료: %s\n", filename);
}

void read_diary() {
	char date[9];	//날짜 입력
	char filename[32];	//파일 이름 저장
	char line[256];	

	//날짜 입력
	printf("열어볼 날짜를 입력하세요 (YYYYMMDD): ");
	scanf("%s", date);

	//파일 이름 생성
	snprintf(filename, sizeof(filename), "diary_%s.txt", date);

	//읽기 모드로 파일 열기
	FILE* fp = fopen(filename, "r");
	if (!fp) {
		printf("파일이 존재하지 않습니다.\n");
		return;
	}

	//한 줄씩 읽어 출력
	printf("==== %s 일기 내용 ====\n", date);
	while (fgets(line, sizeof(line), fp)) {
		printf("%s", line);
	}
	fclose(fp);	//파일 닫기
	printf("\n=====================\n");
}

int main() {
	int choice;
	while (1) {
		printf("\n[1] 일기 쓰기\n[2] 일기 읽기\n[0] 종료\n선택: ");
		scanf("%d", &choice);
		getchar();

		switch (choice) {
		case 1:
			write_diary();	//읽기 쓰기 호출
			break;
		case 2:
			read_diary();	//일기 읽기 호출
			break;
		case 0:
			return 0;	//프로그램 종료
		default:
			printf("잘못된 선택입니다\n");
		}
	}
}
