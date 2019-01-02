import imagopy as ocr


def getsessionid():
    id = ocr.something2()
    assert id is not None
    print(id)


if __name__ == "__main__":
    getsessionid()
