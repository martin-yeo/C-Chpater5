#include <stdio.h>
#include <stdlib.h>   // rand() 함수, srand() 함수
#include <time.h>     // time() 함수

void showIntro(void);	//시작화면 예쁘게
void showSuccess(void); //성공시 화면
void showFail(void);	//실패시 화면
void showExit(void);	//종료조건을 입력시 화면
void showEnding(int);	//최종 점수 출력 화면
int showQuestion(int, int, int);	//질문<난이도 레벨> + 답변
int getNumber(int);		//랜덤수 만들기<난이도 레벨>

int main(void) {
	//변수 선언 및 초기 작업
	int num1, num2;
	int level = 1;
	int answer = -1;
	srand(time(NULL));

	//시작 화면 출력
	showIntro();

	//(반복)문제 출제 및 채점
	while (1) {
		//난수 생성
		num1 = getNumber(level); num2 = getNumber(level);

		//문제 출력
		answer = showQuestion(level, num1, num2);

		//맞히면 계속 레벨 업, 틀리면 아웃, -1이면 아웃
		if (answer == -1) {
			showExit(); break;
		}
		else if (answer == num1 * num2) {
			showSuccess();
			level++;
		}
		else {
			showFail(); break;
		}
	}
	//종료 화면
	showEnding(level - 1);

	return 0;
}

void showIntro(void) { //시작 화면 출력 함수
	printf(">> 비밀 구역, 비밀번호 100단계 입력 <<\n\n");
}
void showSuccess(void) {
	printf(">> 정답입니다!!\n\n");
}
void showFail(void) {
	printf(">> 오답입니다!! 종료합니다!\n\n");
}
void showExit(void) {
	printf(">> 종료 버튼이 눌렸습니다!\n\n");
}
void showEnding(int s) { //종료 화면 출력 함수
	printf(">> 비밀번호 %d개를 맞혔습니다!\n\n", s);
}
int showQuestion(int l, int n1, int n2) { //레벨별 문제 출제 함수
	int a;
	printf("\t%2d x %2d = ?\n", n1, n2);
	printf("%d단계 비밀번호를 입력하세요(-1 입력시 종료) : ", l);
	scanf_s("%d", &a);
	return a;
}
int getNumber(int l) { //레벨별 난수 발생 함수
	return rand() % (l * 9) + 1;
}