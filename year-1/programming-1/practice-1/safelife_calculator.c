#include <stdio.h>
#include <stdbool.h>

// Function to calculate IMC
float IMC_Calculator(float weight, float height) {
    float height_m = height / 100.0; // Convert height from cm to m
    return weight / (height_m * height_m);
}


int main (void) {

    printf("--------------------------\n"
            "-- ASEGURANCES SAFELIFE --\n"
            "--------------------------\n \n"
        );
    printf("Benvingut usuari! Aquesta és la calculadora d'asegurances de vida desenvolupada per l'equip de Safelife.\n");
    printf("Per sortir del programa prem Ctrl + C. \n \n");

    
    bool running = true;
    while (running == true) {

        char response;

        //Get client data and validate it
        printf("Introdueix les dades del client: \n");

        // Variables to store client data
        int age;
        int capital;
        bool smoker;
        float weight;
        float height;
        int work_type;
        bool dangerous_sports;

        printf("Introdueix l'edat del client (18-70): ");
        while (scanf("%d", &age) != 1 || age < 18 || age > 70) {
            printf("Error: Introdueix un valor vàlid per l'edat (18-70): ");
            while (getchar() != '\n'); // Clear input buffer
        }   

        printf("Introdueix el capital a assegurar: \n"
                "   1 - 50.000EUR \n"
                "   2 - 100.000EUR \n"
                "   3 - 150.000EUR \n"
                "   4 - 200.000EUR \n"
                "   5 - 300.000EUR \n"
        );
        while (scanf("%d", &capital) != 1 || capital < 1 || capital > 5) {
            printf("Error: Introdueix un valor vàlid per al capital a assegurar (1-5): ");
            while (getchar() != '\n'); // Clear input buffer
        }
        
        printf("El client és fumador? (S/N): ");
        while (scanf(" %c", &response) != 1 || (response != 'S' && response != 'N' && response != 's' && response != 'n')) {
            printf("Error: Introdueix 'S' per sí o 'N' per no: ");
            while (getchar() != '\n'); // Clear input buffer
            if (response == 'S' || response == 's') {
                smoker = true;
            } else if (response == 'N' || response == 'n') {
                smoker = false;
            }
            response = '\0'; // Reset response for next input
        }

        printf("Introdueix el pes del client en kg: ");
        while (scanf("%f", &weight) != 1 || weight <= 0){
            printf("Error: Introdueix un valor vàlid per al pes (major que 0): ");
            while (getchar() != '\n'); // Clear input buffer
        }

        printf("Introduex l'alçada del client en cm: ");
        while (scanf("%f", &height) != 1 || height <= 0){
            printf("Error: Introdueix un valor vàlid per a l'alçada (major que 0): ");
            while (getchar() != '\n'); // Clear input buffer
        }
        
        float IMC = IMC_Calculator(weight, height);
        
        printf("Introdueix el tipus de treball del client (1-3): \n");
        printf("    1 - Risc Baix: Treball d'oficina, docencia \n"
                "    2 - Risc Mitjà: Transport, indústria, manteniment  \n"
                "    3 - Risc Alt: Construcció en altura, bombers, mineria \n");

        while (scanf("%d", &work_type) != 1 || work_type < 1 || work_type > 3) {
            printf("Error: Introdueix un valor vàlid per al tipus de treball (1-3): ");
            while (getchar() != '\n'); // Clear input buffer
        }

        printf("El client practica esports de risc? (S/N): ");
        while (scanf(" %c", &response) != 1 || (response != 'S' && response != 'N' && response != 's' && response != 'n')) {
            printf("Error: Introdueix 'S' per sí o 'N' per no: ");
            while (getchar() != '\n'); // Clear input buffer
            if (response == 'S' || response == 's') {
                dangerous_sports = true;
            } else if (response == 'N' || response == 'n') {
                dangerous_sports = false;
            }
            response = '\0'; // Reset response for next input
        }

        printf("Dades del client: \n");
        printf("----------------------------------------------------------------------------------------------------------\n"
                "| Edat: %d | Fumador: %s | Pes: %.2f kg | Alçada: %.2f cm | Tipus de treball: %d | Esports de risc: %s |\n"
                "----------------------------------------------------------------------------------------------------------\n",
                age, smoker ? "Sí" : "No", weight, height, work_type, dangerous_sports ? "Sí" : "No"
        );

        printf("Son correctes les dades introduïdes? (S/N): ");
        while (scanf(" %c", &response) != 1 || (response != 'S' && response != 'N' && response != 's' && response != 'n')) {
            printf("Error: Introdueix 'S' per sí o 'N' per no: ");
            while (getchar() != '\n'); // Clear input buffer
        }
        if (response == 'N' || response == 'n') {
            printf("Torna a introduir les dades del client.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue; // Restart the loop to re-enter client data
        }

        // Ask if he wants calculate another client or close the program --
        printf("Vols calcular la prima d'un altre client? (S/N): ");
        while (scanf(" %c", &response) != 1 || (response != 'S' && response != 'N' && response != 's' && response != 'n')) {
            printf("Error: Introdueix 'S' per sí o 'N' per no: ");
            while (getchar() != '\n'); // Clear input buffer
        }
        if (response == 'N' || response == 'n') {
            printf("Gràcies per utilitzar la calculadora d'asegurances de vida SafeLife. Fins aviat!\n");
            running = false;
        }
    }
}