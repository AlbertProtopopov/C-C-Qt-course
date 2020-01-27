void setup() {
  pinMode(7, OUTPUT);
  Serial.begin(9600);
  digitalWrite(7, LOW);
}

void loop(){
  if (Serial.available()){  // Функция получает количество байт(символов) доступных для чтения из последовательного интерфейса связи.
    char forward = Serial.read();  // Это те байты которые уже поступили и записаны в буфер последовательного порта. Буфер может хранить до 64 байт.
    
    if(forward == 'z'){
      digitalWrite(8, LOW); digitalWrite(9, LOW); digitalWrite(10, LOW); digitalWrite(11, LOW); digitalWrite(12, LOW); digitalWrite(13, LOW);}
    else if(forward == 'a'){
      digitalWrite(8, LOW); digitalWrite(9, HIGH); digitalWrite(10, HIGH); digitalWrite(11, LOW); digitalWrite(12, HIGH); digitalWrite(13, HIGH);}
    else if(forward == 'b'){
      digitalWrite(8, HIGH); digitalWrite(9, LOW); digitalWrite(10, LOW); digitalWrite(11, HIGH); digitalWrite(12, HIGH); digitalWrite(13, HIGH);}
    else if(forward == 'c'){
      digitalWrite(8, LOW); digitalWrite(9, HIGH); digitalWrite(10, LOW); digitalWrite(11, LOW); digitalWrite(12, HIGH); digitalWrite(13, LOW);}
    else if(forward == 'd'){
      digitalWrite(8, LOW); digitalWrite(9, LOW); digitalWrite(10, HIGH); digitalWrite(11, LOW); digitalWrite(12, LOW); digitalWrite(13, HIGH);}
    else if(forward == 'e'){
      digitalWrite(8, LOW); digitalWrite(9, HIGH); digitalWrite(10, LOW); digitalWrite(11, HIGH); digitalWrite(12, HIGH); digitalWrite(13, HIGH);}
    else if(forward == 'f'){
      digitalWrite(8, HIGH); digitalWrite(9, LOW); digitalWrite(10, HIGH); digitalWrite(11, LOW); digitalWrite(12, HIGH); digitalWrite(13, HIGH);}
    }
}
