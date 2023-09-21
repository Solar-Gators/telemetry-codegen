from pathlib import Path
import shutil, os, pytest
from datamodule.generate import main

@pytest.fixture
def tempwd(tmpdir: Path):
    org_dir = os.getcwd()
    os.chdir(tmpdir)
    yield tmpdir
    os.chdir(org_dir)


@pytest.mark.parametrize(
    "test_dir",
    [
        "8bit",
        "16bit",
        "floats"
    ]
)
def test_golden_template(tempwd: Path, test_dir: str):

    # copy into test directory
    shutil.copytree(Path(__file__).parent / f"goldens/{test_dir}", tempwd, dirs_exist_ok=True)
    shutil.copytree(Path(__file__).parent / "headers", tempwd, dirs_exist_ok=True)

    # generate from config
    main("config.yml")

    # compile tests
    assert os.system('g++ test.cpp RX0.cpp -std=c++11 -o test') == 0

    # run cpp tests
    assert os.system('./test') == 0
