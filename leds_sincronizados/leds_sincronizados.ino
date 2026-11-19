#define LED1 A0
#define BOT1 6

int botaoDaOutraPlaca = 0;

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(BOT1, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
  int botaoDestaPlaca = !digitalRead(BOT1);

  Serial.write((byte)botaoDestaPlaca);

  if (Serial.available() > 0)
  {
    botaoDaOutraPlaca = Serial.read();
  }

  digitalWrite(LED1, botaoDestaPlaca || botaoDaOutraPlaca);
  delay(500);
}
