import vector_algebra

def test_vector_operations():
    v1 = vector_algebra.Vector3D(1.0, 2.0, 3.0)
    v2 = vector_algebra.Vector3D(4.0, 5.0, 6.0)
    print ("Вектор v1: ",v1)
    print ("Вектор v2: ",v2)
    # Тест сложения
    v3 = v1 + v2
    print("v1+v2: ",v3)

    # Тест вычитания
    v4 = v1 - v2
    print ("v1-v2: ",v4)

    # Тест скалярного произведения
    dot_product = v1.dot(v2)
    print("Салярное произведение векторов v1 и v2: ",dot_product)

    # Тест длины вектора
    length_v1 = v1.length()
    print ("Длина вектора v1: ",length_v1)

if __name__ == "__main__":
    test_vector_operations()
    print("Все тесты пройдены успешно!")
