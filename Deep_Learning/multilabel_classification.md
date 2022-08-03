> Compare of classification types

1. Task
- binary-class: 두 클래스 중 하나를 선택
- multi-class: 여러 클래스 중 하나를 선택
- multi-label: 여러 클래스 중 1개 이상의 클래스를 선택

2. Activation Function
- binary-class: sigmoid, 사실상 yes_or_no 문제이므로 하나의 클래스에 대한 예측값을 1과 0의 극단치로 조정
- multi-class: softmax, 각 클래스별 예측값의 총합이 1인 확률값
- multi-label: sigmoid, 각각의 클래스에 대한 예측값을 1과 0의 극단치로 조정해 해당 클래스를 포함하는가, 아닌가를 분류. 총합은 1을 넘을 수 있음 
