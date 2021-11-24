# unsigned char

c언어에서 unsigned char는 각 bit를 있는 그대로 보는 역할을 한다. signed 형은 bit체계에서 가장 앞 자릿수를 음수로 표현한다고 정의하므로 비트의 있는 그대로 모습이 아닌 표현하는 사람의 '해석'이 들어가는 것이다.

문자열같은 메모리 배열에 접근하는 함수 내부에서 unsigned char 형으로 각 바이트값을 다루는 이유는 바로 이 때문이다. 물론 128 이상의 값을 가지는 확장아스키코드가 존재하는 이유도 있겠지만 unsigned char 형 자체가 값을 다루는 범위가 크기 때문에 모든 가능한 예외 상황을 처리하기 위해서는 안전하게 unsigned char로 문자열을 다루는 것이 좋다.

추가로, c 명세에서 object representation(메모리배열)를 unsigned char[n] 형태의 메모리에 복사 가능한 객체로 정의하고 있다.


