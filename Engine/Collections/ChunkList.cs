using System.Runtime.InteropServices;

namespace Vetche2D.Engine.Collections
{
    public class ChunkList<TElement>
        where TElement : struct
    {

        public sealed class Handle : IDisposable
        {
            public TElement Element
            {
                get => _chunkList._chunks[_chunkIndex][_elementIndex].Data;
                set => _chunkList._chunks[_chunkIndex][_elementIndex].Data = value;
            }

            private ChunkList<TElement> _chunkList;
            private int _chunkIndex;
            private uint _elementIndex;

            public Handle(ChunkList<TElement> parent, int chunkIndex, uint elementIndex)
            {
                _chunkList = parent;
                _chunkIndex = chunkIndex;
                _elementIndex = elementIndex;
            }

            public void Dispose()
            {
                _chunkList._chunks[_chunkIndex][_elementIndex].IsFree = false;
            }
        }

        private struct ElementContainer
        {
            public TElement Data;
            public bool IsFree;
            public uint NextChunk;
            public uint NextElement;
        }

        /// <summary>
        /// _chunks is a list of references to packed arrays containing elements.
        /// </summary>
        private List<ElementContainer[]> _chunks;

        private readonly uint _chunkSize;

        public ChunkList(uint chunkSize)
        {
            _chunkSize = chunkSize;
            _chunks = new();
        }

        public Handle? Add(TElement value)
        {
            if (_chunks.Count == 0)
            {
                var handle = new Handle(this, 0, 0);
                _chunks.Add(new ElementContainer[_chunkSize]);
                handle.Element = value;
                return handle;
            }
            return null;
        }        
    }
}