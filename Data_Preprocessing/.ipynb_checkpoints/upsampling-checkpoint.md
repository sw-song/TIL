# upsampling code
> *reference : kaggle, [Heart Attack Prediction_95.4% accuracy, Avinash Bagul](https://www.kaggle.com/avibagul80/heart-attack-prediction)*
---
**이진분류 문제 중 현재 y값의 분포가 다른 상황**
```python
df.output.value_counts()
```
```
1    163
0    134
Name: output, dtype: int64
```
---
**sklearn을 활용해 비율을 맞춰준다(0값 수를 163개로 upsampling)**

```python
from sklearn.utils import resample #sklearn.uitls의 resample 패키지 활용

# Seperate Targer Classes(이진 분류 문제)
df_1 = df[df.output==1] # y값이 1인 df만 할당
df_2 = df[df.output==0] # y값이 0인 df만 할당 

# Upsample minority class
df_upsample_1 = resample(df_2,
                         replace=True, #sample with replacement
                         n_samples=163, #to match majority class
                         random_state=123, #reproducible results
                        )

# Combine majority class with upsampled minority class
df_upsampled = pd.concat([df_1, df_upsample_1]) # 기존에 값이 134개였던 df_2는 사용하지 않고 값을 163개로 upsampling한 df_upsample_1을 df_1와 concat

# Display new class counts
df_upsampled.output.value_counts()
```
```
1    163
0    163
Name: output, dtype: int64
```
---
