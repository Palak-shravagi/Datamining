
import math
from itertools import combinations
from csv import writer


def read_data_in_dict(filename):
    f = open(filename)
    lines = f.readlines()
    transactions = []
    items = lines[0].split(',')
    for line in lines[1:]:
        transactions.append(list(map(int, line.split(','))))
    data = {
        'items': items,
        'transactions': transactions
    }
    return data


data = read_data_in_dict(
    '/home/palak/Documents/assignments/dm/datafile/freqitem.csv')


def get_freq(s, items, transactions):
    freq = 0
    for t in transactions:
        temp = 1
        for item in s:
            temp *= t[items.index(item)]
        if temp == 1:
            freq += 1
    return freq


def append_list_as_row(file_name, list_of_elem):
    with open(file_name, 'a+', newline='') as write_obj:
        csv_writer = writer(write_obj)
        csv_writer.writerow(list_of_elem)


def frequent_itemsets(data, level, min_support):
    items = data['items']
    transactions = data['transactions']
    min_freq = math.ceil(min_support*len(transactions))
    sets = list(combinations(items, level))
    frequent_sets = []
    for s in sets:
        freq = get_freq(s, items, transactions)
        if freq >= min_freq:
            frequent_sets.append(s)
    print(frequent_sets)
    append_list_as_row(
        '/home/palak/Documents/assignments/dm/datafile/freqitem.csv', frequent_sets)

    return frequent_sets


frequent_itemsets(data, 2, 0.5)
