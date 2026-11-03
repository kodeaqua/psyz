import os


def add_custom_arguments(parser):
    parser.add_argument(
        "--psyq-version",
        choices=("400", "470"),
        default=os.environ.get("PSYQ_VER", "400"),
        help="PSY-Q version to compare (default: PSYQ_VER or 400)",
    )
    parser.add_argument(
        "--library",
        default=None,
        help="library name for the given function",
    )
    parser.add_argument(
        "--overlay",
        help="alias for --library",
    )

def apply(config, args):
    lib = args.library
    if not args.library:
        lib = args.overlay
    version = args.psyq_version
    source_root = "src" if version == "400" else "src/470"
    config["arch"] = "mipsel"
    config["objdump_executable"] = "mipsel-linux-gnu-objdump"
    config["baseimg"] = f"build/psyq{version}_org.elf"
    config["myimg"] = f"build/psyq{version}.elf"
    config["mapfile"] = f"build/psyq{version}.map"
    config["source_directories"] = [
        f"{source_root}/{lib}",
    ]
