using System.Xml;
using System.Xml.Linq;

namespace _253505_Shpakovsky_Lab5;

using System.Collections.Generic;
using System.IO;
using System.Xml.Serialization;
using System.Text.Json;

public class Serializer : ISerializer<Book>
{
    public IEnumerable<Book> DeSerializeByLINQ(string fileName)
    {

        var xml = XDocument.Load(fileName);
        var books = xml.Descendants("Book")
           .Select(b => new Book
           {
               Title = (string)b.Element("Title"),
               Author = (string)b.Element("Author")
           }).ToList();

        return books;
    }

    public IEnumerable<Book> DeSerializeXML(string fileName)
    {
        using (var stream = new FileStream(fileName, FileMode.Open))
        {
            var serializer = new XmlSerializer(typeof(List<Book>));
            return (List<Book>)serializer.Deserialize(stream);
        }
    }

    public IEnumerable<Book> DeSerializeJSON(string fileName)
    {
        using (var stream = new StreamReader(fileName))
        {
            var json = stream.ReadToEnd();
            return JsonSerializer.Deserialize<List<Book>>(json);
        }
    }

    public void SerializeByLINQ(IEnumerable<Book> books, string fileName)
    {

        var xml = new XDocument(
           new XElement("Books", books.Select(b =>
               new XElement("Book",
                   new XElement("Title", b.Title),
                   new XElement("Author", b.Author)
               )
           ))
        );
        xml.Save(fileName);
    }

    public void SerializeXML(IEnumerable<Book> books, string fileName)
    {
        using (var stream = new FileStream(fileName, FileMode.Create))
        {
            var serializer = new XmlSerializer(typeof(List<Book>));
            serializer.Serialize(stream, books.ToList());
        }
    }

    public void SerializeJSON(IEnumerable<Book> books, string fileName)
    {
        var json = JsonSerializer.Serialize(books);
        File.WriteAllText(fileName, json);
    }
}
