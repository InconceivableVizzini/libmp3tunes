/*
 * Copyright (C) 2008 MP3tunes, LLC
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

/**
 * \file oboe.h
 * \brief The \e liboboe public header.
 */

#ifndef __MP3TUNES_LOCKER_H__
#define __MP3TUNES_LOCKER_H__

#include <glib-object.h>

#define MP3TUNES_SERVER_API_URL "ws.mp3tunes.com"
#define MP3TUNES_SERVER_CONTENT_URL "content.mp3tunes.com"
#define MP3TUNES_SERVER_LOGIN_URL "shop.mp3tunes.com"

#define MP3TUNES_SERVER_API 0
#define MP3TUNES_SERVER_CONTENT 1
#define MP3TUNES_SERVER_LOGIN 2

#define MP3TUNES_TYPE_LOCKER                  (mp3tunes_locker_get_type ())
#define MP3TUNES_LOCKER(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), MP3TUNES_TYPE_LOCKER, MP3tunesLocker))
#define MP3TUNES_IS_LOCKER(obj)               (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MP3TUNES_TYPE_LOCKER))
#define MP3TUNES_LOCKER_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), MP3TUNES_TYPE_LOCKER, MP3tunesLockerClass))
#define MP3TUNES_IS_LOCKER_CLASS(klass)       (G_TYPE_CHECK_CLASS_TYPE ((klass), MP3TUNES_TYPE_LOCKER))
#define MP3TUNES_LOCKER_GET_CLASS(obj)        (G_TYPE_INSTANCE_GET_CLASS ((obj), MP3TUNES_TYPE_LOCKER, MP3tunesLockerClass))

typedef struct _MP3tunesLocker MP3tunesLocker;
typedef struct _MP3tunesLockerClass MP3tunesLockerClass;
typedef struct _MP3tunesLockerPrivate MP3tunesLockerPrivate;

struct _MP3tunesLocker {
    GObject parent_instance;

    MP3tunesLockerPrivate *priv;
};

struct _MP3tunesLockerClass {
    GObjectClass parent_class;
};

GType mp3tunes_locker_get_type(void);

typedef struct {
    int trackId;
    char *trackTitle;
    int trackNumber;
    float trackLength;
    char *trackFileName;
    char *trackFileKey;
    int trackFileSize;
    char *downloadURL;
    char *playURL;
    int albumId;
    char *albumTitle;
    int albumYear;
    char *artistName;
    int artistId;
} mp3tunes_locker_track_t;

typedef struct {
    int artistId;
    char* artistName;
    int artistSize;
    int albumCount;
    int trackCount;
} mp3tunes_locker_artist_t;

typedef struct {
    int albumId;
    char *albumTitle;
    int artistId;
    char *artistName;
    int trackCount;
    int albumSize;
    int hasArt;
} mp3tunes_locker_album_t;

typedef struct {
    char* playlistId;
    char* playlistTitle;
    char* title;
    char* fileName;
    int fileCount;
    int playlistSize;
} mp3tunes_locker_playlist_t;

MP3tunesLocker* mp3tunes_locker_new(gchar* partner_token, gchar* device_identifier);
MP3tunesLocker* mp3tunes_locker_new_with_email_and_password(gchar* partner_token, gchar* device_identifier, gchar* email, gchar* password);
GList* mp3tunes_locker_get_playlists(MP3tunesLocker* self);

/*
int mp3tunes_locker_session_valid( mp3tunes_locker_object_t *obj );
int mp3tunes_locker_artists( mp3tunes_locker_object_t *obj, mp3tunes_locker_artist_list_t **artists_return);
int mp3tunes_locker_artists_search( mp3tunes_locker_object_t *obj, mp3tunes_locker_artist_list_t **artists_return, char *query);
int mp3tunes_locker_albums_with_artist_id( mp3tunes_locker_object_t *obj, mp3tunes_locker_album_list_t **albums_return, int artist_id);
int mp3tunes_locker_albums( mp3tunes_locker_object_t *obj, mp3tunes_locker_album_list_t **albums_return);
int mp3tunes_locker_albums_search(  mp3tunes_locker_object_t *obj, mp3tunes_locker_album_list_t **albums_return, char *query);
int mp3tunes_locker_playlists(mp3tunes_locker_object_t *obj, mp3tunes_locker_playlist_list_t **playlist_return);
int mp3tunes_locker_search(mp3tunes_locker_object_t *obj, mp3tunes_locker_artist_list_t **artists_return, mp3tunes_locker_album_list_t **albums_return, mp3tunes_locker_track_list_t **tracks_return, char *query);

int mp3tunes_locker_tracks( mp3tunes_locker_object_t *obj, mp3tunes_locker_track_list_t **tracks_return);
int mp3tunes_locker_tracks_search( mp3tunes_locker_object_t *obj, mp3tunes_locker_track_list_t **tracks_return, char *query);
int mp3tunes_locker_tracks_with_playlist_id( mp3tunes_locker_object_t *obj, mp3tunes_locker_track_list_t **tracks_return, char* playlist_id);
int mp3tunes_locker_tracks_with_album_id( mp3tunes_locker_object_t *obj, mp3tunes_locker_track_list_t **tracks_return, int album_id);
int mp3tunes_locker_tracks_with_artist_id( mp3tunes_locker_object_t *obj, mp3tunes_locker_track_list_t **tracks_return, int artist_id);
int mp3tunes_locker_tracks_with_file_key( mp3tunes_locker_object_t *obj, char *file_keys, mp3tunes_locker_track_list_t **tracks );
int mp3tunes_locker_track_with_file_key( mp3tunes_locker_object_t *obj, char *file_key, mp3tunes_locker_track_t **track );

int mp3tunes_locker_track_list_deinit( mp3tunes_locker_track_list_t** list );
int mp3tunes_locker_artist_list_deinit( mp3tunes_locker_track_list_t** list );
int mp3tunes_locker_album_list_deinit( mp3tunes_locker_track_list_t** list );
int mp3tunes_locker_playlist_list_deinit( mp3tunes_locker_track_list_t** list );

char* mp3tunes_locker_generate_download_url_from_file_key(mp3tunes_locker_object_t *obj, char *file_key);
char* mp3tunes_locker_generate_download_url_from_file_key_and_bitrate(mp3tunes_locker_object_t *obj, char *file_key, char* bitrate);

char* mp3tunes_locker_generate_filekey(const char *filename);
int mp3tunes_locker_upload_track(mp3tunes_locker_object_t *obj, char *path);
int mp3tunes_locker_load_track(mp3tunes_locker_object_t *obj, char *url);

int mp3tunes_locker_sync_down(mp3tunes_locker_object_t *obj, char* type, char* bytes_local, char* files_local, char* keep_local_files, char* playlist_id);
*/
#endif
