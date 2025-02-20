int trigPin = 13;
int echoPin = 12;

int ledPin = 8;

long duration;
int distance;

void setup() {
  // Inicializar los pines
  pinMode(trigPin, OUTPUT);  // El pin TRIG debe ser de salida
  pinMode(echoPin, INPUT);   // El pin ECHO debe ser de entrada
  pinMode(ledPin, OUTPUT);   // El LED debe ser de salida

  // Iniciar la comunicación serial
  Serial.begin(9600);
}

void loop() {
  // Emitir una señal de 10 microsegundos para activar el sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Leer la duración del pulso en el pin Echo
  duration = pulseIn(echoPin, HIGH);

  // Calcular la distancia en centímetros (velocidad del sonido: 343 m/s)
  distance = duration * 0.0344 / 2;


  // Si la distancia es menor a 10 cm, encender el LED
  if (distance < 10) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);  
  }

  delay(100);
}
