import math

class LogisticRegression:
    def __init__(self, lr=0.1, iter=1000):
        self.lr = lr
        self.iter = iter
        self.w = []
        self.b = 0.0

    def sigmoid(self, z):
        return 1 / (1 + math.exp(-z))

    def fit(self, X, y):
        n_samples = len(X)
        n_features = len(X[0])

        
        self.w = [0.0] * n_features
        self.b = 0.0

        for _ in range(self.iter):
            for i in range(n_samples):
                z = sum(self.w[j] * X[i][j] for j in range(n_features)) + self.b
                y_hat = self.sigmoid(z)

                error = y_hat - y[i]

                
                for j in range(n_features):
                    self.w[j] -= self.lr * error * X[i][j]

                self.b -= self.lr * error

    def predict(self, X):
        preds = []
        for x in X:
            z = sum(self.w[j] * x[j] for j in range(len(x))) + self.b
            preds.append(1 if self.sigmoid(z) >= 0.5 else 0)
        return preds

    def accuracy(self, y_true, y_pred):
        correct = 0
        for i in range(len(y_true)):
            if y_true[i] == y_pred[i]:
              correct += 1
        return correct / len(y_true)



X = [
    [0, 0],
    [0, 1],
    [1, 0],
    [1, 1]
]
y = [0, 1, 1, 0]

model = LogisticRegression(lr=0.1, iter=2000)
model.fit(X, y)

predictions = model.predict(X)

print("Predictions:", predictions)
print("Actual:     ", y)
print("Accuracy:",model.accuracy(y, predictions))




