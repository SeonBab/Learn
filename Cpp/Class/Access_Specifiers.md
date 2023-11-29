# 접근지정자(Access Specifiers)

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
  Rect(int w = 2, int h = 2) : width(w), height(h) {} // public 멤버 함수
  int getArea() { return width * height; }            // public 멤버 함수
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

public은 접근 지정자를 갖는 멤버 변수와 멤버 함수는 클래스 외부에서 접근이 가능하다.

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