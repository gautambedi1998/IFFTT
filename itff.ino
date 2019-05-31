#define LIGHT_PIN A0 
#define LIGHT_LEVEL_THRESHOLD 500

int led = D6;

void setup() {
 pinMode(led, OUTPUT);
 digitalWrite(led, LOW);
} 
void loop() { 
   // value decreases as brightness increases 
   int lightLevel = analogRead(LIGHT_PIN); 

   if (lightLevel >= LIGHT_LEVEL_THRESHOLD) { 
       Particle.publish("light", "bright", PRIVATE); 
       digitalWrite(led, LOW);
   } 
   else { 
       Particle.publish("light", "dark", PRIVATE); 
       digitalWrite(led, HIGH);
   } 
}

