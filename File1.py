from matplotlib import pyplot as plt
from math import log2

Full_Path = "C:\\Users\\Артем\\Desktop\\MyC++Projects\\Sorts\\data\\"

legend = []


def display_sort(name, colour, legend_name):
    with open(Full_Path + name + ".txt", "r") as txtObj:
        content = txtObj.read().split("\n")
    points = [list(map(float, content[i].split())) for i in range(len(content))]
    points.pop()

    x = [points[i][0] for i in range(len(points))]
    y = [points[i][1] for i in range(len(points))]

    #for i in range(len(points)):
    #   y[i] /= (x[i] * log2(x[i]))

    plt.plot(x, y, c=colour)

    legend.append(legend_name)


'''display_sort("bubble", "black", "Сортировка пузырьком")
display_sort("insert", "grey", "Сортировка вставками")
display_sort("choice", "purple", "Сортировка выбором")'''


#display_sort("merge", "red", "Сортировка слиянием")
#display_sort("quick", "blue", "Быстрая сортировка")
#display_sort("sepmerge_s", "green", "Сортировка слиянием подпоследовательностей (C)")
#display_sort("sepmerge_u", "pink", "Сортировка слиянием подпоследовательностей (Н)")
#display_sort("cnt", "black", "Сортировка подсчётом")


display_sort("merge1", "red", "Сортировка слиянием")
display_sort("quick1", "blue", "Быстрая сортировка")
display_sort("sepmerge_s1", "green", "Сортировка слиянием подпоследовательностей (C)")
display_sort("sepmerge_u1", "pink", "Сортировка слиянием подпоследовательностей (Н)")


#display_sort("merge1", "red", "Сортировка слиянием")
#display_sort("quick1", "blue", "Быстрая сортировка")
#display_sort("sepmerge1", "green", "Сортировка слиянием подпоследовательностей")

plt.legend(legend)
plt.grid()

plt.title("Сортировки")
#plt.ylabel('Среднее время работы (мс)')
plt.ylabel('Константа (у.е.)')
plt.xlabel('Размер массива')
plt.show()
