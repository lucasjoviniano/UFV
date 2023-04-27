let rec bubble_pass lst = 
  match lst with
  | [] -> []
  | [x] -> [x]
  | x1 :: x2 :: xs -> if x1 > x2 then [x2] @ bubble_pass [x1] @ xs
  else [x1] @ bubble_pass [x2] @ xs

let rec bubble_sort lst = 
  let b_passed = (bubble_pass lst) in
  if b_passed = lst then lst
  else bubble_sort b_passed
