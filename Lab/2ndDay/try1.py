def combine_guests(guests1, guests2):
  # Combine both dictionaries into one, with each key listed 
  # only once, and the value from guests1 taking precedence
  a = dict()
  for i in guests2:
      a[i] = guests2[i]
  for i in guests1:
      a[i] = guests1[i]
  return a
  

Rorys_guests = { "Adam":2, "Brenda":3, "David":1, "Jose":3, "Charlotte":2, "Terry":1, "Robert":4}
Taylors_guests = { "David":4, "Nancy":1, "Robert":2, "Adam":1, "Samantha":3, "Chris":5}

print(combine_guests(Rorys_guests, Taylors_guests))
