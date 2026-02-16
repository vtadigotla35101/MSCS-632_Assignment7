let mean lst =
  let sum = List.fold_left (fun acc x -> acc + x) 0 lst in
  float_of_int sum /. float_of_int (List.length lst)

let median lst =
  let sorted = List.sort compare lst in
  let len = List.length sorted in
  if len mod 2 <> 0 then
    float_of_int (List.nth sorted (len / 2))
  else
    let mid = len / 2 in
    float_of_int (List.nth sorted (mid - 1) + List.nth sorted mid) /. 2.0

let mode lst =
  let counts = Hashtbl.create (List.length lst) in
  List.iter (fun x -> 
    let curr = if Hashtbl.mem counts x then Hashtbl.find counts x else 0 in
    Hashtbl.replace counts x (curr + 1)
  ) lst;
  let max_freq = Hashtbl.fold (fun _ v acc -> max v acc) counts 0 in
  Hashtbl.fold (fun k v acc -> if v = max_freq then k :: acc else acc) counts []

let () =
  let data = [4; 1; 2; 2; 3] in
  Printf.printf "Mean: %.2f\n" (mean data);
  Printf.printf "Median: %.2f\n" (median data);
  List.iter (Printf.printf "Mode: %d ") (mode data);
  print_newline ()