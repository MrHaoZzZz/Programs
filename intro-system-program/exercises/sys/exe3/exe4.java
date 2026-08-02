import java.util.ArrayList ;

public class exe4
{
    static void main( String[] args )
    {
        Song song1 = new Song("A Dandelion’s Promise", "Jay Chou", 2007, "OnTheRun05.mp3");
        Song song2 = new Song("Cruel Summer", "Taylor Swift", 2019, "Cruel_Summer.mp3");
        System.out.println(song1.getArtist()); // Prints "Jay Chou"

        Playlist playlist1 = new Playlist();
        playlist1.addSong(song1);
        playlist1.addSong(song2);
        System.out.println(playlist1.length()); // Prints 2
        System.out.println(playlist1.getSong(2).getFilename()); // Prints "Cruel_Summer.mp3"

        MusicPlayer mp = new MusicPlayer();
        System.out.println(mp.isCurrentlyPlaying()); // Prints false
        mp.startPlaying(playlist1);
        System.out.println(mp.isCurrentlyPlaying()); // Prints true
        System.out.println(mp.currentSong().getName()); // Prints "A Dandelion’s Promise"
        mp.nextSong();
        System.out.println(mp.isCurrentlyPlaying()); // Prints true
        System.out.println(mp.currentSong().getName()); // Prints "Cruel Summer"
        mp.nextSong();
        System.out.println(mp.isCurrentlyPlaying()); // Prints false
    }
}

class Song
{
    String name ;
    String artist ;
    int year ;
    String filename ;

    Song( String name , String artist , int year , String filename )
    {
        this.name = name ;
        this.artist = artist ;
        this.year = year ;
        this.filename = filename ;
    }

    String getName()
    {
        return this.name ;
    }

    String getArtist()
    {
        return this.artist ;
    }

    @SuppressWarnings("unused")
    int getYear()
    {
        return this.year ;
    }

    String getFilename()
    {
        return this.filename ;
    }
}

class Playlist
{
    ArrayList<Song> songs ;

    Playlist()
    {
        songs = new ArrayList<>() ;
    }

    void addSong( Song song )
    {
        this.songs.add( song ) ;
    }

    int length()
    {
        return this.songs.size() ;
    }

    Song getSong( int index )
    {
        return this.songs.get( index - 1 );
    }
}

class MusicPlayer
{
    boolean isPlaying ;
    int index ;
    Playlist playlist ;

    MusicPlayer() { this.isPlaying = false ; }

    void startPlaying( Playlist playlist )
    {
        this.playlist = playlist ;
        this.isPlaying = true ;
        this.index = 0 ;
    }

    @SuppressWarnings("unused")
    void stopPlaying()
    {
        this.isPlaying = false ;
    }

    void nextSong()
    {
        if ( this.index < this.playlist.length() - 1 )
        {
            this.index ++ ;
        }
        else
        {
            this.isPlaying = false ;
        }
    }

    boolean isCurrentlyPlaying()
    {
        return this.isPlaying ;
    }

    Song currentSong()
    {
        return this.playlist.getSong( this.index + 1 ) ;
    }
}