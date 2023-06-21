//
// Created by jcpremizov on 20.06.23.
//

#ifndef FINAL_PROJECT_RESTAURANT_H
#define FINAL_PROJECT_RESTAURANT_H
class Restaurant{
public:
    static inline float balance = 200000;

    static void saveToJson() {
        json jsonData;
        jsonData["balance"] = balance;

        std::ofstream file("restaurant.json");
        if (file.is_open()) {
            file << jsonData.dump(4);  // Записываем JSON-данные в файл с отступами (4 пробела)
            file.close();
            std::cout << "Сохранение успешно выполнено." << std::endl;
        } else {
            std::cerr << "Не удалось открыть файл для сохранения." << std::endl;
        }
    }

    // Функция загрузки из JSON
    static void loadFromJson() {
        std::ifstream file("restaurant.json");
        if (file.is_open()) {
            json jsonData;
            file >> jsonData;
            file.close();

            if (jsonData.contains("balance")) {
                balance = jsonData["balance"].get<float>();
                std::cout << "Загрузка успешно выполнена." << std::endl;
            } else {
                std::cerr << "Файл JSON не содержит необходимых данных." << std::endl;
            }
        } else {
            std::cerr << "Не удалось открыть файл для загрузки." << std::endl;
        }
    }
};
#endif //FINAL_PROJECT_RESTAURANT_H
