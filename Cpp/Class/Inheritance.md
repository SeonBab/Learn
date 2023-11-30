# 상속(Inheritance)

상속을 통해 기존 클래스에서 새 클레스를 파생할 수 있다. \
파생에 사용되는 클래스를 특정 파생 클래스의 기본, 부모, 상위 클래스 라고 한다. \
파생 클래스는 자식, 하위, 유도, 서브 클래스라고 부른다. \

상속은 ia-a관계가 있는 경우에만 상속을 한다.

장점으로 다음과 같다.
+ 코드의 중복 작성을 없애 클래스를 간결하게 구현 할 수 있게된다.
+ 관련 클래스를 계층 관계로 표현함으로서 클래스들의 구조적인 관계 파악을 쉽게 해준다.

파생 클래스는 다음 구문을 사용하여 선언된다.

```
class 클래스이름 : 접근지정자 부모클래스이름
{
    멤버 리스트
    ...
}
```
```
class PrintedDocument {};

class Book : public PrintedDocument {};

class PaperbackBook : public Book {};
```

그림으로 다음과 같이 상속하고 있는데, 이는 단일 상속이다.

![single_inheritance](https://learn.microsoft.com/ko-kr/cpp/cpp/media/vc38xj1.gif?view=msvc-170)

위의 경우 `Book`이 `PrintedDocument`에서 파생 클래스인 동시에 기본 클래스다.

`Book`은 일종의 `PrintedDocument`이고, `PaperbackBook`은 일종의`Book`이다. \
`PrintedDocument`는 `Book`의 "직접 기본" 클래스로 간주되며 `PaperbackBook`의 "간접 기본" 클래스다. 이 두 클래스 간의 차이점으로 직접 기본 클래스는 클래스 선언의 기본 목록에 표시되지만 간접 기본 클래스는 표시되지 않는다.

각 클래스가 파생되는 기본 클래스는 파생 클래스의 선언 이전에 선언되어야 한다. 기본 클래스에 대한 전방 참조 선언만을 제공하는 것으로는 부족하고, 완전한 선언을 제공해야 한다.

상속을 받고, 파생 클래스는 기본 클래스의 멤버와 새로 추가하는 멤버를 포함한다. 따라서 파생 클래스는 기본 클래스의 멤버를 참조 할 수 있다. \
기본 클래스의 멤버를 참조 할 때 멤버의 접근 지정자에 영향을 받지만 상속 시 정한 클래스의 접근 지정자에 영향을 받기도 한다. \
멤버 접근 지정자와 상속 접근 지정자의 경우 제한이 더 높은 지정자로 변경된다. \
예로는 다음과 같다.

<table>
    <tr>
        <td>상속 접근 지정자</td>
        <td>기본 클래스</td>
        <td>파생 클래스</td>
    </tr>
    <tr>
        <td rowspan="3">public</td>
        <td>public</td>
        <td>public</td>
    </tr>
    <tr>
        <td>protected</td>
        <td>protected</td>
    </tr>
    <tr>
        <td>private</td>
        <td>private</td>
    </tr>
        <tr>
        <td rowspan="3">protected</td>
        <td>public</td>
        <td>protected</td>
    </tr>
    <tr>
        <td>protected</td>
        <td>protected</td>
    </tr>
    <tr>
        <td>private</td>
        <td>private</td>
    </tr>
        </tr>
        <tr>
        <td rowspan="3">private</td>
        <td>public</td>
        <td>private</td>
    </tr>
    <tr>
        <td>protected</td>
        <td>private</td>
    </tr>
    <tr>
        <td>private</td>
        <td>private</td>
    </tr>
</table>

