/* Sensor ultrasónico HC-SR04*/
// define los números de los pines
const int trigPin = 9;
const int echoPin = 10;
// define las variables
long duracion;
int distancia;
void setup() {
  // define los pines como entrada o salida
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // inicia la comunicación serial
  Serial.begin(9600);
}
void loop() {
  // envía un pulso de 10 microsegundos al pin trigPin para activar el sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // mide la duración del pulso en el pin echoPin
  duracion = pulseIn(echoPin, HIGH);
  // calcula la distancia en centímetros
  distancia = duracion * 0.034 / 2;
  // imprime la distancia en el monitor serial
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
  // espera 500 milisegundos antes de volver a medir
  delay(500);
}
