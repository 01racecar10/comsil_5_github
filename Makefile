OBJECTS = main.o # OBJECTS에 컴파일된 오브젝트 파일 저장
SRC = main.cpp # SRC에 컴파일할 소스 파일 저장

CC = g++ # 컴파일러 지정
CFLAGS = -c # 컴파일 옵션 설정

TARGET = main # 빌드할 대상 프로그램의 이름 지정

# 빌드된 대상 프로그램 생성
$(TARGET): $(OBJECTS) LinkedList.h Stack.h
        $(CC) -o $(TARGET) $(OBJECTS)

# 불필요한 파일 정리
clean:
        rm $(OBJECTS) $(TARGET)