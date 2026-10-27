#include <stdio.h>
#include <stdbool.h>

//--- VARIABLES ---
// System variables
bool running = true;
char response;

//TODO: Implement new constants for insurance modalities and fractions of payment, base prizes per capital

// Variables to store client data
int age;
int capital;
bool smoker;
float weight;
float height;
int work_type;
bool dangerous_sports;

//--- FUNCTIONS ---
float IMC_Calculator(float weight, float height) {
    float height_m = height / 100.0; // Convert height from cm to m
    return weight / (height_m * height_m);
}

//TODO: Validate user input for integers, example: 20.5 error.
int int_validator(int min, int max) {
    int value;
    while (scanf("%d", &value) != 1 || value < min || value > max) {
        printf("Error: Introdueix un valor vàlid (%d-%d): ", min, max);
        while (getchar() != '\n'); // Clear input buffer
    }
    return value;
}

float float_validator(float min, float max) {
    float value;
    while (scanf("%f", &value) != 1 || value < min || value > max) {
        printf("Error: Introdueix un valor vàlid (%.2f-%.2f): ", min, max);
        while (getchar() != '\n'); // Clear input buffer
    }
    return value;
}

bool true_false_validator() {
    char response;
    while (scanf(" %c", &response) != 1 || (response != 'S' && response != 'N' && response != 's' && response != 'n')) {
        printf("Error: Introdueix 'S' per sí o 'N' per no: ");
        while (getchar() != '\n'); // Clear input buffer
    }
    if (response == 'S' || response == 's') {
        return true;
    } else if (response == 'N' || response == 'n') {
        return false;
    }
    response = '\0'; // Reset response for next input
}

//--- MAIN FUNCTION ---
int main (void) {

    printf("--------------------------\n"
            "-- ASEGURANCES SAFELIFE --\n"
            "--------------------------\n \n"
        );
    printf("Benvingut usuari! Aquesta és la calculadora d'asegurances de vida desenvolupada per l'equip de Safelife.\n");
    printf("Per sortir del programa prem Ctrl + C. \n \n");

    while (running == true) {

        //Get client data and validate it
        printf("Introdueix les dades del client: \n");

        printf("Introdueix l'edat del client (18-70): ");
        age = int_validator(18, 70);

        printf("Introdueix el capital a assegurar: \n"
                "   1 - 50.000EUR \n"
                "   2 - 100.000EUR \n"
                "   3 - 150.000EUR \n"
                "   4 - 200.000EUR \n"
                "   5 - 300.000EUR \n"
        );
        capital = int_validator(1, 5);

        printf("El client és fumador? (S/N): ");
        smoker = true_false_validator();

        printf("Introdueix el pes del client en kg: ");
        weight = float_validator(1, 300);

        printf("Introduex l'alçada del client en cm: ");
        height = float_validator(1, 300);
        
        float IMC = IMC_Calculator(weight, height);
        
        printf("Introdueix el tipus de treball del client (1-3): \n");
        printf("    1 - Risc Baix: Treball d'oficina, docencia \n"
                "    2 - Risc Mitjà: Transport, indústria, manteniment  \n"
                "    3 - Risc Alt: Construcció en altura, bombers, mineria \n");
        work_type = int_validator(1, 3);

        printf("El client practica esports de risc? (S/N): ");
        dangerous_sports = true_false_validator();

        printf("Dades del client: \n");
        printf("----------------------------------------------------------------------------------------------------------\n"
                "| Edat: %d | Fumador: %s | Pes: %.2f kg | Alçada: %.2f cm | Tipus de treball: %d | Esports de risc: %s |\n"
                "----------------------------------------------------------------------------------------------------------\n",
                age, smoker ? "Sí" : "No", weight, height, work_type, dangerous_sports ? "Sí" : "No"
        );

        printf("Son correctes les dades introduïdes? (S/N): \n");
        if (true_false_validator() == false) {
            printf("Si us plau, torna a introduir les dades del client. \n");
            continue; // Restart the loop to re-enter client data
        }
        
        //TODO: Implement the insurance modalities and calculate the prize per client based on the data provided, modalities, and fractions of payment.

        //--- CLOSE PROGRAM ---
        // Ask if the user wants to calculate for another client
        printf("Vols calcular la prima d'un altre client? (S/N): ");
        running = true_false_validator();
        if (running == false) {
            printf("Gràcies per utilitzar la calculadora d'asegurances de vida de Safelife. Fins aviat! \n");
        }
    }
}