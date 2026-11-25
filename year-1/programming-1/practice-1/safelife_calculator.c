#include <stdio.h>

//--- VARIABLES ---
// System variables
int running = 1;
char response;

//TODO: Implement new constants for insurance modalities and fractions of payment, base prizes per capital
// Variables to store insurance modalities and fractions of payment
int basic_insurance = 0;
int extended_insurance = 30;
int premium_insurance = 55;
int base_rate;
int risk_percentatge;

float client_rate;

// Variables to store client data
int age;
int capital;
int smoker;
float weight;
float height;
int work_type;
int dangerous_sports;

//--- FUNCTIONS ---
float IMC_Calculator(float weight, float height) {
    return weight / (height * height);
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

int true_false_validator() {
    char response;
    while (scanf(" %c", &response) != 1 || (response != 'S' && response != 'N' && response != 's' && response != 'n')) {
        printf("Error: Introdueix 'S' per sí o 'N' per no: ");
        while (getchar() != '\n'); // Clear input buffer
    }
    if (response == 'S' || response == 's') {
        return 1;
    } else if (response == 'N' || response == 'n') {
        return 0;
    }
    response = '\0'; // Reset response for next input
}

void calculate_insurance(int age, int capital, int smoker, float IMC, int work_type, int dangerous_sports) {
    //Base rates per capital
    if (capital == 1) {base_rate = 90;}
    else if (capital == 2) {base_rate = 160;}
    else if (capital == 3) {base_rate = 225;}
    else if (capital == 4) {base_rate = 280;}
    else if (capital == 5) {base_rate = 390;}

    // Calculate total percentatge based on client data
    if (age >= 18 && age <= 29) {risk_percentatge = -10;}
    else if (age >= 30 && age <= 39) {risk_percentatge = 0;}
    else if (age >= 40 && age <= 49) {risk_percentatge = 25;}
    else if (age >= 50 && age <= 59) {risk_percentatge = 60;}
    else if (age >= 60 && age <= 65) {risk_percentatge = 110;}
    else if (age >= 66 && age <= 70) {risk_percentatge = 180;}

    if (smoker == 1) {risk_percentatge += 45;}

    if (IMC < 18.5) {risk_percentatge += 15;}
    else if (IMC >= 25 && IMC < 30) {risk_percentatge += 10;}
    else if (IMC >= 30) {risk_percentatge += 30;}

    if (work_type == 2) {risk_percentatge += 15;}
    else if (work_type == 3) {risk_percentatge += 40;}

    if (dangerous_sports == 1) {risk_percentatge += 20;}

    client_rate = base_rate * risk_percentatge / 100.0f + base_rate;

    printf("\nEls preus de l'assegurança segons les dades introduïdes són els següents:\n\n");
    printf("IMC: %.2f | Prima base: %.2f EUR | Risc total: %.2f%%\n",
           IMC, (float)base_rate, (float)risk_percentatge);
    printf("Prima total: %.2f EUR\n\n", client_rate);

    printf("---------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-13s | %22s | %22s | %22s | %22s |\n",
           "Modalitat", "Anual (1 rebut)", "Semestral (2 rebuts)",
           "Trimestral (4 rebuts)", "Mensual (12 rebuts)");
    printf("---------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-13s | %22.2f | %22.2f | %22.2f | %22.2f |\n",
           "Basica", client_rate, client_rate * 1.03f / 2.0f,
           client_rate * 1.05f / 4.0f, client_rate * 1.08f / 12.0f);
    printf("---------------------------------------------------------------------------------------------------------------------\n");
    if (age <= 65) {
        float extended_rate = client_rate * (1.0f + extended_insurance / 100.0f);
        printf("| %-13s | %22.2f | %22.2f | %22.2f | %22.2f |\n",
               "Ampliada", extended_rate, extended_rate * 1.03f / 2.0f,
               extended_rate * 1.05f / 4.0f, extended_rate * 1.08f / 12.0f);
    } else {
        printf("| %-13s | %22s | %22s | %22s | %22s |\n",
               "Ampliada", "No disponible", "No disponible",
               "No disponible", "No disponible");
    }
    printf("---------------------------------------------------------------------------------------------------------------------\n");
    if (age <= 60) {
        float premium_rate = client_rate * (1.0f + premium_insurance / 100.0f);
        printf("| %-13s | %22.2f | %22.2f | %22.2f | %22.2f |\n",
               "Premium", premium_rate, premium_rate * 1.03f / 2.0f,
               premium_rate * 1.05f / 4.0f, premium_rate * 1.08f / 12.0f);
    } else {
        printf("| %-13s | %22s | %22s | %22s | %22s |\n",
               "Premium", "No disponible", "No disponible",
               "No disponible", "No disponible");
    }
    printf("---------------------------------------------------------------------------------------------------------------------\n");

}

//--- MAIN FUNCTION ---
int main (void) {

    printf("--------------------------\n"
            "-- ASEGURANCES SAFELIFE --\n"
            "--------------------------\n \n"
        );
    printf("Benvingut usuari! Aquesta és la calculadora d'asegurances de vida desenvolupada per l'equip de Safelife.\n");
    printf("Per sortir del programa prem Ctrl + C. \n \n");

    while (running == 1) {

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

        printf("Introdueix el pes del client en kg (30-200): ");
        weight = float_validator(30, 200);

        printf("Introdueix l'alçada del client en metres (1.00-2.50): ");
        height = float_validator(1, 2.5);
        
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
                "| Edat: %d | Fumador: %s | Pes: %.2f kg | Alçada: %.2f m | Tipus de treball: %d | Esports de risc: %s |\n"
                "----------------------------------------------------------------------------------------------------------\n",
                age, smoker ? "Sí" : "No", weight, height, work_type, dangerous_sports ? "Sí" : "No"
        );

        printf("Son correctes les dades introduïdes? (S/N): \n");
        if (true_false_validator() == 0) {
            printf("Si us plau, torna a introduir les dades del client. \n");
            continue; // Restart the loop to re-enter client data
        }
        
        calculate_insurance(age, capital, smoker, IMC, work_type, dangerous_sports);


        //--- CLOSE PROGRAM ---
        // Ask if the user wants to calculate for another client
        printf("Vols calcular la prima d'un altre client? (S/N): ");
        running = true_false_validator();
        if (running == 0) {
            printf("Gràcies per utilitzar la calculadora d'asegurances de vida de Safelife. Fins aviat! \n");
        }
    }
}