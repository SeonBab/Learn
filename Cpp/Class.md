# 클래스(Class)

일상에서의 객체를 프로그램 코드로 표현하기 위한 사용자 정의 자료형이다. C++ 언어의 객체는 자신만의 고유한 상태(state) 정보를 저장하고 있는 멤버 변수(속성)와 객체의 행동(behavior)에 해당하는 멤버 함수(기능)로 구성된다. 행동으로 객체의 상태가 변화하거나 객체의 상태가 외부로 전달되기도 한다.

클래스는 C의 구조체에서 확장된 C++ 구조체의 또다른 이름이라고 볼 수 도 있다. 클래스는 함수를 포함 할 수 있으며, 기본 접근 제한자에 차이가 있을 뿐 거의 같다. \
클래스와 구조체가 동일한 기능을 하면서 존재하는 이유는 C++에서 C와의 하위 호환성을 위해 남겨졌다고 볼 수 있다.


# 클래스 선언과 정의

```
class 클래스이름 // 클래스 이름의 자료형을 정의
{
    접근지정자:
    멤버 변수 선언1; // 객체의 상태 또는 특성에 해당하는 변수 "자료형 변수이름"의 형태로 선언
    멤버 변수 선언2;
    ...

    멤버 함수 선언1; // 객체의 기능에 해당하는 함수 "반환자료형 함수이름(인수 리스트)"의 형태로 선언
}; // 세미콜론(;)으로 끝내야한다.

class Rect
{
    public:
    int width;      // 멤버 변수 선언
    int height;
    int getArea();  // 멤버 함수 선언
};
```

멤버 함수의 경우 클래스 정의 내 정의되거나 클래스 정의 밖에서 정의할 수 있다.멤버 함수를 클래스 정의 밖에서 정의하는 구문은 다음과 같다.

```
반환자료형 클래스이름::함수이름(인수리스트) // 멤버 함수 정의
{
    ...
}

int Rect::getArea()
{
    return width * height;
}
```

클래서 정의 영역 내부에서 getArea() 함수의 정의는 다음과 같다.
```
class Rect
{
    public:
    int width, height;
    int getArea() { return width * height; }  // 멤버 함수 정의
};
```

멤버 함수를 클래스 정의 영역 내부에 정의할 경우 간결해 보일 수 있으나 멤버 함수의 개수가 많은 경우 클래스의 전체 구조를 한 눈에 파악하기 어렵다. 그러므로 가능하면 클래스의 정의와 멤버 함수의 정의를 분리하여 표현하는 것이 일반적이다.

클래스의 멤버 변수와 멤버 함수는 멤버 선택 연산자(.)를 사용해 접근 할 수 있다.

# 접근지정자(Access specifiers)

C++의 접근 지정자는 private, protected, public의 세 가지 접근 지정 키워드가 있다. 이 접근지정자는 C++의 데이터 캡슐화와 관련이 있다.

private 접근 지정자를 갖는 멤버 변수, 멤버 함수는 클래스 외부에서 접근이 불가능한 것으로 클래스 내부의 멤버 함수에 의해서만 접근이 가능하다.

클래스는 기본적으로 모든 멤버 변수와 멤버 함수는 private 접근 지정자를 가진다.

```
class Rect
{
  int width;    // private 멤버 변수
private:
  int height;   // private 멤버 변수 
public:
  Rect(int w = 2, int h = 2) : width(w), height(h)  // public 멤버 함수
  int getArea() { return width * height; }          // public 멤버 함수
 };
 
int main()
{
  Rect rectangle;
  rectangle.width = 5;  // 접근 오류
  rectangle.height = 4; // 접근 오류
  
  cout << "Width: " << rectangle.width<< endl;  // 접근 오류
  cout << "Area: " << rectangle.getArea() << endl; 

  return 0;
}
```

컴파일하면 다음과 같이 세 곳에서 에러가 발생한다.

```
error: 'width' is a private member of 'Rect'
  rectangle.width = 5;                          // 접근 오류
            ^
error: 'height' is a private member of 'Rect'
  rectangle.height = 4;                         // 접근 오류
            ^
error: 'width' is a private member of 'Rect'
  cout << "Width: " << rectangle.width<< endl;  // 접근 오류
```

반면 public은 접근 지정자를 갖는 멤버 변수와 멤버 함수는 클래스 외부에서 접근이 가능하다.

그렇기에 위에 예시에서 `cout << "Area: " << rectangle.getArea() << endl;`는 컴파일 에러가 발생하지 않고 멤버 함수에 접근이 가능하다.

protected는 private 접근 지정자와 비슷하게 클래스 외부에서는 protected 멤버에 접근하지 못하나 상속을 받는 자식 클래스 내부의 멤버들은 접근이 가능하다. 이 접근 지정자는 상속 관계에서만 의미를 가진다. \
private 접근 지정자로 지정된 멤버는 상속 받은 자식 클래스 내부에서도 접근이 불가능하다.

```
class Shape
{
protected:
  int pointX, pointY;   // protected 멤버 변수
public:
  Shape(int x = 2, int y = 2) : pointX(x), pointY(y) {}
  void printPoint() { cout <<"point: " << pointX << ", " << pointY << endl; } 
};
 
class Rect : public Shape     // Shape 클래스를 상속받는 Rect 클래스 
{
private:
    int width, height;
public:
 	Rect(int w, int h) : width(w), height(h) {}
 	void printEndpoint()
    {
 		cout <<"Rect: " << pointX + width << ", " << pointY + height << endl;
 	}
};
```

부모 클래스의 pointX, pointY 멤버 변수가 protected 접근 지정자로 지정되어 있으므로 상속받은 Rect 클래스의 멤버 함수에서 접근 할 수 있다.

# 생성자(Constructor)

