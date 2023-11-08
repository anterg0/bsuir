using _253505_Shpakovsky_Lab5;

var library = new Library
{
    Books = new List<Book>
    {
        new Book { Title = "Book 1", Author = "Author 1" },
        new Book { Title = "Book 2", Author = "Author 2" },
    }
};

var serializer = new Serializer();

serializer.SerializeByLINQ(library.Books, "booksByLINQ.xml");
serializer.SerializeXML(library.Books, "booksXML.xml");
serializer.SerializeJSON(library.Books, "booksJSON.json");

var deserializedBooksByLINQ = serializer.DeSerializeByLINQ("booksByLINQ.xml");
var deserializedBooksXML = serializer.DeSerializeXML("booksXML.xml");
var deserializedBooksJSON = serializer.DeSerializeJSON("booksJSON.json");

