use rand::Rng;

fn main() {
    let (p, q) = generate_keys();

    let n = p * q;

    let phi = (p - 1) * (q - 1);

    let e = generate_e(phi);

    let d = generate_d(e, phi);

    println!("P: {}, Q: {}, N: {}, D: {}", p, q, n, d);
}

fn generate_keys() -> (i64, i64) {
    let mut p: i64 = 0;
    let mut q: i64 = 0;

    let mut rng = rand::thread_rng();

    while q == 0 {
        let random: i64 = rng.gen_range(10000..i32::MAX) as i64;

        if fermat_primality_test(random) {
            q = random;
        }
    }

    while p == 0 {
        let random: i64 = rng.gen_range(10000..i32::MAX) as i64;

        if fermat_primality_test(random) && random != q {
            p = random;
        }
    }

    (p, q)
}

fn generate_e(phi: i64) -> i64 {
    let mut rng = rand::thread_rng();

     loop {
        let number = rng.gen::<i32>() as i64;
        if is_coprime(number, phi) {
            return number;
        }
    }
}

fn generate_d(e: i64, phi: i64) -> i64 {
    let (_rest, s, _t) = extended_mdc(e, phi);

    s
}

// https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm
fn extended_mdc(a: i64, b: i64) -> (i64, i64, i64) {

    let mut r = a;
    let mut r_old = b;

    let mut s = 1i64;
    let mut s_old = 0i64;

    let mut t = 0i64;
    let mut t_old = 1i64;

    while r_old != 0 {
        let q = r / r_old;
        let rs = r;
        let ss = s;
        let ts = t;

        r = r_old;
        s = s_old;
        t = t_old;

        r_old = rs - q * r_old;
        s_old = ss - q * s;
        t_old = ts - q * t_old;
    }

    (r, s, t)
}

fn fermat_primality_test(prime: i64) -> bool {

    let factors = generate_coprimes(prime, 10);

    factors
        .into_iter()
        .all( |factor| mod_pow(factor, prime - 1, prime) == 1)
}

fn generate_coprimes(prime: i64, n: usize) -> Vec<i64>{
    (2..)
        .into_iter()
        .filter(|n| is_coprime(prime, *n))
        .take(n)
        .collect()
}

fn is_coprime(a: i64, b:i64) -> bool {
    mdc(a, b) == 1
}

fn mdc(a: i64, b: i64) -> i64 {
    if b != 0 {
        mdc(b, a % b)
    } else {
        a
    }
}

// http://www.cs.ucf.edu/~dmarino/progcontests/modules/matexpo/RecursionFastExp.pdf
fn mod_pow(base: i64, exponent: i64, modulo: i64) -> i64 {
    let number = base % modulo;

    if exponent == 0 {
        1
    } else if exponent == 1 {
        number
    } else if exponent % 2 == 0 {
        mod_pow(number * number % modulo, exponent / 2, modulo)
    } else {
        number * mod_pow(number, exponent - 1, modulo) % modulo
    }
}