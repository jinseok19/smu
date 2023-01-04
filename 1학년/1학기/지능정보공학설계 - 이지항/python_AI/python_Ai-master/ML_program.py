
import matplotlib.pyplot as plt
from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn import tree
from sklearn.metrics import accuracy_score

def plot_accuracy(prediction, truth):
    
    acc = accuracy_score(prediction, truth)
    print(acc)
    return acc

test_list = ['0.7', '0.5', '0.3']
result_list = []
iris = datasets.load_iris()


x = iris.data
y = iris.target
for i in test_list:
    x_train, x_test, y_train, y_test = train_test_split(x, y, test_size= float(i))

    clf = tree.DecisionTreeClassifier()
    clf.fit(x_train, y_train)

    predctions = clf.predict(x_test)
    print(i,'test_size') 
    print('예측: \n', predctions)
    print('정답(y_test): \n', y_test)

    result_list.append(plot_accuracy(predctions, y_test))
  

print(result_list)
bar = plt.bar(test_list, result_list)
for rect in bar:
    height = rect.get_height()
    plt.text(rect.get_x() + rect.get_width()/2.0, height, '%.3f' % height, ha='center', va='bottom', size = 12)
plt.title('Results of accuracy')
plt.xlabel('test_size')
plt.ylabel('accuracy')
plt.show()