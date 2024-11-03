// Встановлення пінів для світлодіодів та кнопки
const int led1 = 2;       // Пін для першого світлодіода
const int led2 = 3;       // Пін для другого світлодіода
const int buttonPin = 4;  // Пін для кнопки

// Змінні для зберігання стану кнопки та світлодіодів
int buttonState = 0;       // Поточний стан кнопки
int lastButtonState = 0;   // Попередній стан кнопки
bool activeLed = false;    // Стан активного світлодіода (false - перший, true - другий)

void setup() {
  // Налаштування пінів як вихід та вхід
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Підтягування кнопки до HIGH

  // Вимкнути обидва світлодіоди на початку
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}

void loop() {
  // Читання поточного стану кнопки
  buttonState = digitalRead(buttonPin);

  // Перевірка, чи було натискання кнопки (перехід від HIGH до LOW)
  if (buttonState == LOW && lastButtonState == HIGH) {
    // Перемикання активного світлодіода
    activeLed = !activeLed;

    // Затримка для уникнення "дребезгу" контактів
    delay(50);
  }

  // Оновлення попереднього стану кнопки
  lastButtonState = buttonState;

  // Встановлення стану світлодіодів відповідно до активного світлодіода
  if (activeLed) {
    // Увімкнути другий світлодіод, вимкнути перший
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  } else {
    // Увімкнути перший світлодіод, вимкнути другий
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }
}
