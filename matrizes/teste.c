void MelhorCaracteristica (float Matriz [][6], int Caracteristica){
  system("clear");
  float MelhorCar = 0;
  int i;
  char MelhorFrz [5];
  if (Caracteristica == 3) {
    for (i=0; i<6; i++){
      if (Matriz [Caracteristica][i] < MelhorCar) {
        MelhorCar = Matriz[0][i];
        if (i==0) strcpy(MelhorFrz,"Deia");
        if (i==1) strcpy(MelhorFrz,"Sul");
        if (i==2) strcpy(MelhorFrz,"Nsul");
        if (i==3) strcpy(MelhorFrz,"Frio");
        if (i==4) strcpy(MelhorFrz,"Fri");
        if (i==5) strcpy(MelhorFrz,"Lux");
      }
    }
  }
  else {
    for (i=0; i<6; i++){
      if (Matriz [Caracteristica][i] > MelhorCar) {
        MelhorCar = Matriz[0][i];
        if (i==0) strcpy(MelhorFrz,"Deia");
        if (i==1) strcpy(MelhorFrz,"Sul");
        if (i==2) strcpy(MelhorFrz,"Nsul");
        if (i==3) strcpy(MelhorFrz,"Frio");
        if (i==4) strcpy(MelhorFrz,"Fri");
        if (i==5) strcpy(MelhorFrz,"Lux");
      }
    }
  }

  if (i==0) printf("O melhor freezer %s tem %f de capacidade e é o melhor nesse aspecto.\n", MelhorFrz, MelhorCar);
  if (i==1) printf("O melhor freezer %s tem %f de garantia e é o melhor nesse aspecto.\n", MelhorFrz, MelhorCar);
  if (i==2) printf("O melhor freezer %s tem %f de economia e é o melhor nesse aspecto.\n", MelhorFrz, MelhorCar);
  if (i==3) printf("O melhor freezer %s tem %f de temperatura e é o melhor nesse aspecto.\n", MelhorFrz, MelhorCar);
}











void MelhorCaracteristica (float Matriz [][6], int Caracteristica){
  system("clear");
  float MelhorCar = 0;
  int i;
  char MelhorFrz [5];
  for (i=0; i<6; i++){
    if (Matriz [Caracteristica][i] > MelhorCar) {
      MelhorCar = Matriz[0][i];
      if (i==0) strcpy(MelhorFrz,"Deia");
      if (i==1) strcpy(MelhorFrz,"Sul");
      if (i==2) strcpy(MelhorFrz,"Nsul");
      if (i==3) strcpy(MelhorFrz,"Frio");
      if (i==4) strcpy(MelhorFrz,"Fri");
      if (i==5) strcpy(MelhorFrz,"Lux");
    }
  }
  printf ("O melhor freezer em capacidade é o %s e tem %.1f de capacidade.\n", MelhorFrz, MelhorCar);
}