TaskHandle_t task1; //initializing the tasks with the type TaskHandle_t; these variables should be used to reference the tasks
TaskHandle_t task2;

void setup() {
  
  Serial.begin(115200); 

  xTaskCreatePinnedToCore(task1Func, "task1Name", 10000, NULL, 1, &task1, 0); 
  //name of the task function, task name, stack size (in words), parameter, priority (low number = low priority), task handle (defined earlier), core to run task on 
           
  delay(500); 

  xTaskCreatePinnedToCore(task2Func, "task2Name", 10000, NULL, 1, &task2, 1); 
  
  delay(500); 
  
}

void task1Func( void * pvParameters ){

  for(;;){
    //loop
  } 
  
}

//Task2code: blinks an LED every 700 ms
void task2Func( void * pvParameters ){

  for(;;){
    //loop
  }
  
}

void loop() {
  //nothing should really be here
}
