# TIL(Today I Learned) - C, Statistics, Data Science, ML/DL, Python, Git

### C
- [1d/2d-array with pointer](https://github.com/sw-song/TIL/blob/main/C/arr_pnt.c)
- [show address in 2d-array](https://github.com/sw-song/TIL/blob/main/C/address_2d_array.c)
- [malloc and realloc](https://github.com/sw-song/TIL/blob/main/C/realloc.c)
- [linked list - make single node](https://github.com/sw-song/TIL/blob/main/C/single_node.c)
- [linked list - make multi node](https://github.com/sw-song/TIL/blob/main/C/linked_list.c)
- [binary search tree - malloc and free](https://github.com/sw-song/TIL/blob/main/C/bin_search_tree.c)
- [size_t in C](https://github.com/seungson/TIL/blob/main/C/size_t.md)
---

### Data Preprocessing
- [Normalization vs Standardization](https://github.com/sw-song/TIL/blob/main/Data_Preprocessing/Normalization_vs_Standardization.md)
- [Remove Outlier (Functionalization)](https://github.com/sw-song/TIL/blob/main/Data_Preprocessing/remove_outlier.md)
- [upsampling (match the number of 'y - 0,1' in classification model)](https://github.com/sw-song/TIL/blob/main/Data_Preprocessing/upsampling.md)
- [LabelEncoder vs OneHotEncoder vs LabelBinarizer](https://github.com/sw-song/TIL/blob/main/Data_Preprocessing/sklearn_Encoders.md)
---

### Pandas DataFrame
- [reset_index(drop=True)](https://github.com/sw-song/TIL/blob/main/Pandas_DataFrame/reset_index.md)
- [df[col].ffill()](https://github.com/sw-song/TIL/blob/main/Pandas_DataFrame/ffill.md)
- [pd.melt(df, id_vars, value_vars, var_name, value_name)](https://github.com/sw-song/TIL/blob/main/Pandas_DataFrame/melt.md)
---

### Feature Engineering
- [feature_selection(from sklearn) - RFE(Recursive Feature Elimination)](https://github.com/sw-song/TIL/blob/main/Feature_Engineering/rfe.md)
---

### Visualization
- [Seaborn - basic visualization (flights dataset)](https://github.com/sw-song/TIL/blob/main/Visualization/sns_visualization.ipynb)
---

### Machine Learning (Modeling)
- [K-Nearest Neighbor Algorithm](https://github.com/sw-song/TIL/blob/main/Machine_Learning/KNN.md)
- [Random Forest Classifier](https://github.com/sw-song/TIL/blob/main/Machine_Learning/RandomForestClassifier.md)
- [Gradient Boosting Classifier](https://github.com/sw-song/TIL/blob/main/Machine_Learning/GradientBoostingClassifier.md)
- [Hyper-Parameter Tuning, GridSearchCV(from sklearn.model_selection)](https://github.com/sw-song/TIL/blob/main/Machine_Learning/GridSearchCV.md)
- [GridSearchCV(n_jobs=estimator=Model(), param_grid=param_grid, ... , **multiprocessing.cpu_count()**)]
- [make_pipeline(from sklearn.pipeline)]
- [XGBoost(Regression/Classification)](https://github.com/sw-song/TIL/blob/main/Machine_Learning/XGBoost.md)
- [lightgbm(Regression/Classification)](https://github.com/sw-song/TIL/blob/main/Machine_Learning/LGBM.md)
---

### Deep Learning (Modeling)
- [data 'class_mode' and Model Compile 'loss']
- [Conv2D(.. **padding='same'**)]
- [Conv2D and BatchNormalization]
- [Multiple Object Detection with 2 Step(R-CNN/SPP-Net/Fast R-CNN/Faster R-CNN)](https://github.com/sw-song/TIL/blob/main/Deep_Learning/Multiple_Object_Detection_2step.md)
- [GAN - Basic Concept](https://github.com/sw-song/TIL/blob/main/Deep_Learning/GAN.md)
- [StarGAN - Basic Concept](https://github.com/sw-song/TIL/blob/main/Deep_Learning/StarGAN.md)
- [StarGAN v2 - Basic Concept](https://github.com/sw-song/TIL/blob/main/Deep_Learning/StarGAN_v2.md)
- [[Paper] StarGAN v2: Diverse Image Synthesis for Multiple Domains - Yunjey Choi, Youngjung Uh, Jaejun Yoo, Jung-Woo Ha](https://github.com/sw-song/TIL/blob/main/Deep_Learning/Paper_StarGAN_v2.md)
- [CGAN - Conditional GAN]
- [pix2pix model : CycleGAN vs StarGAN](https://github.com/sw-song/TIL/blob/main/Deep_Learning/CycleGAN_vs_StarGAN.md)
- [GAN : Unpaired Image to Image Translation](https://github.com/sw-song/TIL/blob/main/Deep_Learning/GAN_Image_to_Image_Translation.md)
---

### Model Evaluation
- [Explain classification_report(from sklearn.metrics) with examples](https://github.com/sw-song/TIL/blob/main/Model_Evaluation/classification_report.md)
- [confusion_matrix(from sklearn.metrics)](https://github.com/sw-song/TIL/blob/main/Model_Evaluation/confusion_matrix.md)
- [Feature Importance vs Permutation Feature Importance](https://github.com/sw-song/TIL/blob/main/Model_Evaluation/feature_importance.md)
- [Precision and Recall in an Anomaly Detection Situation](https://github.com/sw-song/TIL/blob/main/Model_Evaluation/precision_vs_recall.md)
- [ROC Curve +metrics.plot_roc_curve(model, X_test, y_test)](https://github.com/sw-song/TIL/blob/main/Model_Evaluation/precision_vs_recall.md)
---

### Statistics
- [R Square](https://github.com/sw-song/TIL/blob/main/Statistics/R_Square.md)
- [df.corr() | correlation coefficient - pearson, spearman, kendall tau](https://github.com/sw-song/TIL/blob/main/Statistics/corr.md)
- [scipy.stats.kstest() | Kolmogorov-Smirnov Test](https://github.com/sw-song/TIL/blob/main/Statistics/kstest.md)
- [(statsmodels.api)OLS.from_formula('y ~ x1+x2+x3..', data=df)](https://github.com/sw-song/TIL/blob/main/Statistics/ols_regression.md)


---

### R
- [*Tutorial : (1) Getting Started | Rachael Tatman | Kaggle](https://github.com/sw-song/TIL/blob/main/R/getting-started-in-r-first-steps.ipynb)
- [*Tutorial : (2) Load Data | Rachael Tatman | Kaggle](https://github.com/sw-song/TIL/blob/main/R/getting-started-in-r-load-data-into-r.ipynb)
- [*Tutorial : (3) Summarize Data | Rachael Tatman | Kaggle](https://github.com/sw-song/TIL/blob/main/R/getting-started-in-r-summarize-data.ipynb)
- [*Tutorial : (4) Graphing Data | Rachael Tatman | Kaggle](https://github.com/sw-song/TIL/blob/main/R/getting-started-in-r-graphing-data.ipynb)
- [*Tutorial : Introduction to machine learning in R | Cam Nugent | Kaggle](https://github.com/sw-song/TIL/blob/main/R/introduction-to-machine-learning-in-r-tutorial.ipynb)
---

### SQL
- [INNER JOIN vs OUTER JOIN](https://github.com/sw-song/TIL/blob/main/SQL/inner_outer_join.md)
- [*프로그래머스 | GROUP BY | 동명 동물 수 찾기](https://github.com/sw-song/TIL/blob/main/SQL/having.md)
- [*프로그래머스 | GROUP BY | 입양 시각 구하기(1)](https://github.com/sw-song/TIL/blob/main/SQL/use_alias.md)
- [*프로그래머스 | GROUP BY | 입양 시각 구하기(2)](https://github.com/sw-song/TIL/blob/main/SQL/recursive.md)
- [*프로그래머스 | IS NULL | NULL 처리하기](https://github.com/sw-song/TIL/blob/main/SQL/ifnull.md)
- [*프로그래머스 | JOIN | 없어진 기록 찾기](https://github.com/sw-song/TIL/blob/main/SQL/join_without_null.md)
- [*프로그래머스 | JOIN | 있었는데요 없었습니다](https://github.com/sw-song/TIL/blob/main/SQL/compare_dates.md)
- [INNER JOIN 2 Table / FROM 2 Table](https://github.com/sw-song/TIL/blob/main/SQL/join_and_from_2_table.md)
- [*프로그래머스 | JOIN | 오랜 기간 보호한 동물(1)](https://github.com/sw-song/TIL/blob/main/SQL/order_by_datetime.md)
- [*프로그래머스 | JOIN | 보호소에서 중성화한 동물](https://github.com/sw-song/TIL/blob/main/SQL/intact_to_spayed.md)
- [*프로그래머스 | String, Date | 이름에 el이 들어가는 동물 찾기](https://github.com/sw-song/TIL/blob/main/SQL/where_like_upper_lower.md)
- [*프로그래머스 | String, Date | 중성화 여부 파악하기](https://github.com/sw-song/TIL/blob/main/SQL/if_or_case.md)
- [*프로그래머스 | Summer/Winter Coding(2019) | 우유와 요거트가 담긴 장바구니](https://github.com/sw-song/TIL/blob/main/SQL/with_groupby_having.md)
- [*프로그래머스 | 2021 Dev-Matching: 웹 백엔드 개발자(상반기) | 헤비 유저가 소유한 장소](https://github.com/sw-song/TIL/blob/main/SQL/subquery_or_2table.md)
- [*LeetCode | 181. Employees Earning More Than Their Managers](https://github.com/sw-song/TIL/blob/main/SQL/double_table.md)
- [*LeetCode | 626. Exchange Seats](https://github.com/sw-song/TIL/blob/main/SQL/odd_even_change.md)
---

### Terminal & Git
- [touch vs mkdir (+git status)](https://github.com/sw-song/TIL/blob/main/Git/status.md)
- [branch, checkout](https://github.com/sw-song/TIL/blob/main/Git/brunch.md)
- [git fetch --all & git reset --hard origin/main (overwrite local branch with remote Repository)]
---

### Server
- [System log vs User log](https://github.com/sw-song/TIL/blob/main/Server/log.md)
- [Scheduling](https://github.com/sw-song/TIL/blob/main/Server/scheduling.md)

---

### Markdown
- [Markdown index with inner link](https://github.com/sw-song/TIL/blob/main/Markdown/innerlink.md)
---

### Docker
- [Docker Intro - quick usage](https://github.com/sw-song/TIL/blob/main/Docker/docker_tutorial.md)
