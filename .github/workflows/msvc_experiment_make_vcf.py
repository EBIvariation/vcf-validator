"""Write a deterministic, valid VCF v4.3 file used to time the validator (temporary MSVC experiment)."""
import random
import sys

path = sys.argv[1]
n_records = int(sys.argv[2])
n_samples = 10
rng = random.Random(42)
bases = "ACGT"

with open(path, "w", newline="\n") as out:
    out.write("##fileformat=VCFv4.3\n")
    out.write("##contig=<ID=1,length=249250621>\n")
    out.write('##INFO=<ID=DP,Number=1,Type=Integer,Description="Total depth">\n')
    out.write('##INFO=<ID=AF,Number=A,Type=Float,Description="Allele frequency">\n')
    out.write('##FILTER=<ID=q10,Description="Quality below 10">\n')
    out.write('##FORMAT=<ID=GT,Number=1,Type=String,Description="Genotype">\n')
    out.write('##FORMAT=<ID=DP,Number=1,Type=Integer,Description="Read depth">\n')
    out.write('##FORMAT=<ID=GQ,Number=1,Type=Integer,Description="Genotype quality">\n')
    samples = "\t".join("S%d" % i for i in range(1, n_samples + 1))
    out.write("#CHROM\tPOS\tID\tREF\tALT\tQUAL\tFILTER\tINFO\tFORMAT\t%s\n" % samples)
    pos = 1000
    for i in range(n_records):
        pos += rng.randint(1, 200)
        ref = rng.choice(bases)
        alt = rng.choice([b for b in bases if b != ref])
        genotypes = "\t".join(
            "%s:%d:%d" % (rng.choice(["0/0", "0/1", "1/1", "./."]), rng.randint(1, 99), rng.randint(1, 99))
            for _ in range(n_samples)
        )
        out.write("1\t%d\trs%d\t%s\t%s\t%d\t%s\tDP=%d;AF=%.3f\tGT:DP:GQ\t%s\n" % (
            pos, i + 1, ref, alt, rng.randint(10, 99), rng.choice(["PASS", "q10"]),
            rng.randint(10, 999), rng.random(), genotypes))
