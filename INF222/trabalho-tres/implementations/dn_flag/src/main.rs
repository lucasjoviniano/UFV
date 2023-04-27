fn my_dutch(unordered: &Vec<f32>) -> Vec<f32> {
    let less_than: Vec<f32> = unordered.iter().cloned().filter(|&v| v < 0.).collect();
    let equal: Vec<f32> = unordered.iter().cloned().filter(|&v| v == 0.).collect();
    let greater_than: Vec<f32> = unordered.iter().cloned().filter(|&v| v > 0.).collect();

    less_than
        .iter()
        .cloned()
        .chain(equal.iter().cloned())
        .chain(greater_than.iter().cloned())
        .collect()
}

fn djikstra_dutch(unordered: &Vec<f32>) -> Vec<f32> {
    let mut i = 0;
    let mut j = 0;
    let mut k = unordered.len() - 1;
    let mid: f32 = 0.;
    let mut values = unordered.clone();

    while j <= k {
        if values[j] < mid {
            values.swap(i, j);
            i += 1;
            j += 1;
        } else if values[j] > mid {
            values.swap(j, k);
            k -= 1;
        } else {
            j += 1;
        }
    }

    values
}

fn main() {
    let values: Vec<f32> = vec![0., 1.618, 3.14, 2.718, -1.41, 0.577, 0., 0., -9.8, 0.];

    println!("{:?}", djikstra_dutch(&values));
    println!("{:?}", my_dutch(&values));
}
